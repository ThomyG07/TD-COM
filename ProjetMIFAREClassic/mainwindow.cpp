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
    qDebug() << "OpenCOM" << status;
    ui->ConnectButton->setEnabled(false);
    ui->DisconnectButton->setEnabled(true);
    EnableConfiguration(true);

    status = Version(&MonLecteur);
    qDebug() << "Version" << status;

    status = RF_Power_Control(&MonLecteur, TRUE, 0);
    qDebug() << "Power On" << status;

    //status = Version(&MonLecteur);
    //ui->Affichage->setText(MonLecteur.version);
    //ui->Affichage->update();
}
void MainWindow::on_DisconnectButton_clicked()
{
    RF_Power_Control(&MonLecteur, FALSE, 0);
    LEDBuzzer(&MonLecteur, LED_OFF);
    CloseCOM(&MonLecteur);
    ui->ConnectButton->setEnabled(true);
    ui->DisconnectButton->setEnabled(false);
    EnableConfiguration(false);
}

void MainWindow::on_ExitButton_clicked()
{
    int16_t status = MI_OK;
    RF_Power_Control(&MonLecteur, FALSE, 0);
    status = LEDBuzzer(&MonLecteur, LED_OFF);
    status = CloseCOM(&MonLecteur);
    qApp -> quit();
}

void MainWindow::on_SelectCardButton_clicked()
{
    int16_t status = MI_OK;

    uint8_t atq = 0;
    uint8_t sak = 0;
    uint8_t uid = 0;
    uint16_t uid_len = 0;

    uint32_t Nom = 10;


    //Wake up de la carte
    status = ISO14443_3_A_PollCardWU(&MonLecteur,&atq, &sak, &uid, &uid_len );


    status = Mf_Classic_Read_Value(&MonLecteur, TRUE, 10, &Nom, TRUE, 2);

    qDebug() << Nom;
}

void MainWindow::initPictures()
{
    QLabel* logo1 = ui->Logo_1;
    logo1->setPixmap(QPixmap("C:/Users/gblan/Documents/GitHub/TD-COM/ProjetMIFAREClassic/Img/OIG2.png"));

    QLabel* logo2 = ui->Logo_2;
    logo2->setPixmap(QPixmap("C:/Users/gblan/Documents/GitHub/TD-COM/ProjetMIFAREClassic/Img/OIG2.png"));

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
