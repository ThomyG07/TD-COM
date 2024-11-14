#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "MfErrNo.h"
#include "Sw_Device.h"
#include "Sw_ISO14443A-3.h"
#include "Sw_Mf_Classic.h"
#include "Tools.h"
#include "TypeDefs.h"
#include <QDebug>
#include <QString>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{ 
    ui->setupUi(this);
    initPictures();
    EnableConfiguration(false);
}


MainWindow::~MainWindow()
{
    delete ui;
}


ReaderName MonLecteur;


void MainWindow::on_ConnectButton_clicked()
{
    int16_t status = MI_OK;
    MonLecteur.Type = ReaderCDC;
    MonLecteur.device = 0;

    status = OpenCOM(&MonLecteur);
    if(status != 0)PopupMessage("Erreur lors de l'ouverture de la communication");

    status = RF_Power_Control(&MonLecteur, TRUE, 0);
    if(status != 0)PopupMessage("Erreur lors de la connection du lecteur");
    else
    {
        ui->ConnectButton->setEnabled(false);
        ui->DisconnectButton->setEnabled(true);
        ui->SelectCardButton->setEnabled(true);
        EnableConfiguration(true);
    }
}


void MainWindow::on_DisconnectButton_clicked()
{
    RF_Power_Control(&MonLecteur, FALSE, 0);
    LEDBuzzer(&MonLecteur, LED_OFF);
    CloseCOM(&MonLecteur);
    ui->ConnectButton->setEnabled(true);
    ui->DisconnectButton->setEnabled(false);
    ui->SelectCardButton->setEnabled(false);
    EnableConfiguration(false);
}


void MainWindow::on_ExitButton_clicked()
{
    int16_t status = MI_OK;
    RF_Power_Control(&MonLecteur, FALSE, 0);
    LEDBuzzer(&MonLecteur, LED_OFF);
    status = CloseCOM(&MonLecteur);
    if(status != 0)PopupMessage("Erreur lors de la fermeture de la connection");
    qApp -> quit();
}


void MainWindow::on_SelectCardButton_clicked()
{
    int16_t status = MI_OK;

    uint8_t atq = 0;
    uint8_t sak = 0;
    uint8_t uid = 0;
    uint16_t uid_len = 0;

    status = ISO14443_3_A_PollCard(&MonLecteur,&atq, &sak, &uid, &uid_len );
    if(status != 0)PopupMessage("Erreur: pour mettre le carte en mode wake up");
    else
    {
        char Nom[16];
        char Prenom[16];

        uint8_t Wallet = 0;

        status = GetDataSector(10, Nom);
        if(status != 0)
        {
            PopupMessage("Erreur: impossible de lire le bloc 10");
            return;
        }

        ui -> lineEdit_5 -> setText(Nom);
        ui -> lineEdit_5 -> update();

        status = GetDataSector(9, Prenom);
        if(status != 0)
        {
            PopupMessage("Erreur: impossible de lire le bloc 9");
            return;
        }

        ui -> lineEdit_6 -> setText(Prenom);
        ui -> lineEdit_6 -> update();

        status = Mf_Classic_Read_Block(&MonLecteur, TRUE, 14, &Wallet, AuthKeyA, 3);
        if(status != 0)
        {
            PopupMessage("Erreur: impossible de lire le bloc 14");
            return;
        }

        auto WalletText = QString::number(Wallet);

        ui -> lineEdit_3 -> setText(WalletText);
        ui -> lineEdit_3 -> update();
    }
}


void MainWindow::on_UpdateButton_clicked()
{

    SetDataSector(10, ui->lineEdit_5);
    SetDataSector(9, ui->lineEdit_6);

    int16_t status = MI_OK;

    char Nom[16];
    char Prenom[16];

    status = GetDataSector(10, Nom);
    if(status != 0)
    {
        PopupMessage("Erreur: impossible d'écrire sur le bloc 10");
        return;
    }

    ui -> lineEdit_5 -> setText(Nom);
    ui -> lineEdit_5 -> update();

    status = GetDataSector(9, Prenom);
    if(status != 0)
    {
        PopupMessage("Erreur: impossible d'écrire sur le bloc 9");
        return;
    }

    ui -> lineEdit_6 -> setText(Prenom);
    ui -> lineEdit_6 -> update();
    LedBuzzerSendData();
}


void MainWindow::initPictures()
{
    QLabel* logo1 = ui->Logo_1;
    logo1->setPixmap(QPixmap(":/icon/Img/OIG2.png"));

    QLabel* logo2 = ui->Logo_2;
    logo2->setPixmap(QPixmap(":/icon/Img/OIG2.png"));
}


void MainWindow::EnableConfiguration(bool isvisible)
{
    QGroupBox * GroupeIdentite = ui->Identite;
    GroupeIdentite->setEnabled(isvisible);

    QGroupBox * GroupeIcrementation = ui->Incrementation;
    GroupeIcrementation->setEnabled(isvisible);

    QGroupBox * GroupeDecrementation = ui->Decrementation;
    GroupeDecrementation->setEnabled(isvisible);
}


void MainWindow::on_ChargeButton_clicked()
{
    uint16_t statusIncrement = MI_OK;
    uint16_t statusRestore = MI_OK;
    uint16_t statusRead = MI_OK;

    uint8_t Wallet;
    uint8_t ChargeValue = ui->spinBox_2->value();

    statusIncrement = Mf_Classic_Increment_Value(&MonLecteur, TRUE, 13, ChargeValue, 13, AuthKeyB, 3);
    if(statusIncrement != 0)
    {
        PopupMessage("Erreur lors de l'incrémentation du bloc 13");
        return;
    }
    statusRestore = Mf_Classic_Restore_Value(&MonLecteur, TRUE,13,14,AuthKeyB,3);
    if(statusRestore != 0)
    {
        PopupMessage("Erreur lors du transfert des données du bloc 13 à 14");
        return;
    }
    statusRead = Mf_Classic_Read_Block(&MonLecteur, TRUE, 14, &Wallet, AuthKeyA, 3);
    if(statusRead != 0)
    {
        PopupMessage("Erreur lors de la lecture du bloc 14");
        return;
    }

    LedBuzzerSendData();

    auto WalletText = QString::number(Wallet);

    ui -> lineEdit_3 -> setText(WalletText);
    ui -> lineEdit_3 -> update();
}


void MainWindow::on_PaieButton_clicked()
{
    uint16_t statusDecrement = MI_OK;
    uint16_t statusRestore = MI_OK;
    uint16_t statusRead = MI_OK;

    uint8_t Wallet;
    uint8_t PayValue = ui->spinBox->value();

    statusDecrement = Mf_Classic_Decrement_Value(&MonLecteur, TRUE, 13, PayValue, 13, AuthKeyA,3);
    if(statusDecrement != 0)
    {
        PopupMessage("Erreur lors de la décrementation du bloc 13");
        return;
    }
    statusRestore = Mf_Classic_Restore_Value(&MonLecteur, TRUE,13,14,AuthKeyB,3);
    if(statusRestore != 0)
    {
        PopupMessage("Erreur lors du transfert des données du bloc 13 à 14");
        return;
    }
    statusRead = Mf_Classic_Read_Block(&MonLecteur, TRUE, 14, &Wallet, AuthKeyA, 3);
    if(statusRead != 0)
    {
        PopupMessage("Erreur lors de la lecture du bloc 14");
        return;
    }

    LedBuzzerSendData();

    auto WalletText = QString::number(Wallet);

    ui -> lineEdit_3 -> setText(WalletText);
    ui -> lineEdit_3 -> update();
}


uint16_t MainWindow::GetDataSector(int sector, char data[16])
{
    uint16_t status = MI_OK;
    status = Mf_Classic_Read_Block(&MonLecteur, TRUE, sector, (unsigned char*)data, AuthKeyA, 2);
    return status;
}


uint16_t MainWindow::SetDataSector(int sector, QLineEdit* Qline)
{
    uint16_t status = MI_OK;

    QString NomSaisi = Qline->text();

    QByteArray byteArray = NomSaisi.toLocal8Bit();
    const char* cstr = byteArray.data();

    char Data[8];
    strncpy(Data, cstr, sizeof(Data) - 1);
    Data[7] = '\0';
    status = Mf_Classic_Write_Block(&MonLecteur, TRUE,sector, (unsigned char*)Data,AuthKeyB,2);

    return status;
}


void MainWindow::LedBuzzerSendData()
{
    for(int i = 0; i<3; i++ )
    {
        LEDBuzzer(&MonLecteur, LED_YELLOW_ON);
        Sleep(10);
        LEDBuzzer(&MonLecteur, LED_YELLOW_OFF);
    }
    LEDBuzzer(&MonLecteur, BUZZER_ON);
    Sleep(10);
    LEDBuzzer(&MonLecteur, BUZZER_OFF);
    LEDBuzzer(&MonLecteur, LED_RED_ON);
}


void MainWindow::PopupMessage(QString msg)
{
    QMessageBox messageBox;
    messageBox.critical(0,"Error",msg);
    messageBox.setFixedSize(500,200);
}
