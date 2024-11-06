/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.17
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *Identite;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QPushButton *UpdateButton;
    QGroupBox *Decrementation;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_6;
    QLineEdit *lineEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QSpinBox *spinBox;
    QPushButton *PaieButton;
    QGroupBox *Incrementation;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpinBox *spinBox_2;
    QPushButton *ChargeButton;
    QPushButton *ExitButton;
    QPushButton *ConnectButton;
    QPushButton *DisconnectButton;
    QPushButton *SelectCardButton;
    QLabel *label_4;
    QLabel *Logo_1;
    QLabel *Logo_2;
    QLabel *label_10;

    void setupUi(QWidget *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        label = new QLabel(MainWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 91, 31));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setWordWrap(false);
        label_2 = new QLabel(MainWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 40, 241, 31));
        QFont font1;
        font1.setBold(false);
        label_2->setFont(font1);
        label_2->setWordWrap(false);
        label_3 = new QLabel(MainWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 60, 331, 31));
        label_3->setFont(font1);
        label_3->setWordWrap(false);
        verticalLayoutWidget = new QWidget(MainWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(370, 80, 361, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Identite = new QGroupBox(verticalLayoutWidget);
        Identite->setObjectName(QString::fromUtf8("Identite"));
        Identite->setEnabled(true);
        verticalLayoutWidget_4 = new QWidget(Identite);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(9, 29, 251, 101));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_8 = new QLabel(verticalLayoutWidget_4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setEnabled(true);

        horizontalLayout_6->addWidget(label_8);

        lineEdit_5 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setEnabled(true);

        horizontalLayout_6->addWidget(lineEdit_5);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(7);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_9 = new QLabel(verticalLayoutWidget_4);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_7->addWidget(label_9);

        lineEdit_6 = new QLineEdit(verticalLayoutWidget_4);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);


        verticalLayout_4->addLayout(horizontalLayout_7);

        UpdateButton = new QPushButton(Identite);
        UpdateButton->setObjectName(QString::fromUtf8("UpdateButton"));
        UpdateButton->setEnabled(true);
        UpdateButton->setGeometry(QRect(270, 70, 80, 24));

        verticalLayout->addWidget(Identite);

        Decrementation = new QGroupBox(verticalLayoutWidget);
        Decrementation->setObjectName(QString::fromUtf8("Decrementation"));
        Decrementation->setEnabled(true);
        verticalLayoutWidget_3 = new QWidget(Decrementation);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(9, 29, 262, 101));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(110);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_6 = new QLabel(verticalLayoutWidget_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_4->addWidget(label_6);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_3);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_4->addWidget(lineEdit_3);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(20);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(verticalLayoutWidget_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_5->addWidget(label_7);

        spinBox = new QSpinBox(verticalLayoutWidget_3);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_5->addWidget(spinBox);


        verticalLayout_3->addLayout(horizontalLayout_5);

        PaieButton = new QPushButton(Decrementation);
        PaieButton->setObjectName(QString::fromUtf8("PaieButton"));
        PaieButton->setGeometry(QRect(270, 120, 80, 24));

        verticalLayout->addWidget(Decrementation);

        Incrementation = new QGroupBox(verticalLayoutWidget);
        Incrementation->setObjectName(QString::fromUtf8("Incrementation"));
        Incrementation->setEnabled(true);
        verticalLayoutWidget_2 = new QWidget(Incrementation);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(9, 29, 241, 41));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(7);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout->addWidget(label_5);

        spinBox_2 = new QSpinBox(verticalLayoutWidget_2);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout->addWidget(spinBox_2);


        verticalLayout_2->addLayout(horizontalLayout);

        ChargeButton = new QPushButton(Incrementation);
        ChargeButton->setObjectName(QString::fromUtf8("ChargeButton"));
        ChargeButton->setGeometry(QRect(270, 40, 80, 24));

        verticalLayout->addWidget(Incrementation);

        ExitButton = new QPushButton(MainWindow);
        ExitButton->setObjectName(QString::fromUtf8("ExitButton"));
        ExitButton->setGeometry(QRect(700, 560, 80, 24));
        ConnectButton = new QPushButton(MainWindow);
        ConnectButton->setObjectName(QString::fromUtf8("ConnectButton"));
        ConnectButton->setEnabled(true);
        ConnectButton->setGeometry(QRect(80, 510, 80, 24));
        DisconnectButton = new QPushButton(MainWindow);
        DisconnectButton->setObjectName(QString::fromUtf8("DisconnectButton"));
        DisconnectButton->setEnabled(false);
        DisconnectButton->setGeometry(QRect(200, 510, 80, 24));
        SelectCardButton = new QPushButton(MainWindow);
        SelectCardButton->setObjectName(QString::fromUtf8("SelectCardButton"));
        SelectCardButton->setGeometry(QRect(80, 540, 201, 24));
        label_4 = new QLabel(MainWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 560, 121, 31));
        label_4->setFont(font);
        label_4->setWordWrap(false);
        Logo_1 = new QLabel(MainWindow);
        Logo_1->setObjectName(QString::fromUtf8("Logo_1"));
        Logo_1->setGeometry(QRect(10, 150, 341, 331));
        Logo_1->setPixmap(QPixmap(QString::fromUtf8("Img/OIG2.png")));
        Logo_1->setScaledContents(true);
        Logo_1->setWordWrap(false);
        Logo_2 = new QLabel(MainWindow);
        Logo_2->setObjectName(QString::fromUtf8("Logo_2"));
        Logo_2->setGeometry(QRect(660, 0, 101, 81));
        Logo_2->setPixmap(QPixmap(QString::fromUtf8("Img/OIG2.png")));
        Logo_2->setScaledContents(true);
        Logo_2->setWordWrap(false);
        label_10 = new QLabel(MainWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(570, 20, 91, 31));
        label_10->setFont(font);
        label_10->setWordWrap(false);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QWidget *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Porte monnaie", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cette application montre le fonctionnement", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "d'un porte monnaie \303\251lectronique sur carte MIFARE Classic 1k", nullptr));
        Identite->setTitle(QCoreApplication::translate("MainWindow", "Identit\303\251", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Prenom", nullptr));
        UpdateButton->setText(QCoreApplication::translate("MainWindow", "Mise \303\240 jour", nullptr));
        Decrementation->setTitle(QCoreApplication::translate("MainWindow", "Dr\303\251cr\303\251menter le porte monnaie", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251s", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251s \303\240 d\303\251cr\303\251menter", nullptr));
        PaieButton->setText(QCoreApplication::translate("MainWindow", "Payer", nullptr));
        Incrementation->setTitle(QCoreApplication::translate("MainWindow", "Incr\303\251menter le porte monnaie", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Nombre d'unit\303\251s \303\240 incr\303\251menter", nullptr));
        ChargeButton->setText(QCoreApplication::translate("MainWindow", "Charger", nullptr));
        ExitButton->setText(QCoreApplication::translate("MainWindow", "Quitter", nullptr));
        ConnectButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        DisconnectButton->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        SelectCardButton->setText(QCoreApplication::translate("MainWindow", "Selectionner la carte", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Porte monnaie v1.00", nullptr));
        Logo_1->setText(QString());
        Logo_2->setText(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "Team Bouclette", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
