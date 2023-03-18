#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_MotorCalistir_clicked();
    void on_Ayarla_clicked();
    void on_MotorDurdur_clicked();
    void on_BaglantiyiKes_clicked();


    void on_Ayarla_2_clicked();

    void on_pushButton_clicked();

    void on_BaglantiyiKes_pressed();
    void Read_Data();


private:
    Ui::MainWindow *ui;
    QSerialPort *serial;

};
#endif // MAINWINDOW_H
