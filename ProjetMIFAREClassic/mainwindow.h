#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <qlineedit.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initPictures();
    void EnableConfiguration(bool isvisible);
    uint16_t GetDataSector(int sector, char data[16]);
    uint16_t SetDataSector(int sector, QLineEdit* qline);
    void LedBuzzerSendData();
    void PopupMessage(QString msg);
private slots:
    void on_ConnectButton_clicked();
    void on_DisconnectButton_clicked();
    void on_ExitButton_clicked();
    void on_SelectCardButton_clicked();
    void on_UpdateButton_clicked();
    void on_ChargeButton_clicked();
    void on_PaieButton_clicked();

};
#endif // MAINWINDOW_H
