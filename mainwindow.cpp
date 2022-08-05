#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFile"
#include "QTextStream"
#include "QDateTime"


QString filename = "C:/deneme.txt";
QFile file(filename);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   ui->setupUi(this);
    foreach(const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
   {
       QSerialPort serial;
       serial.setPort(info);
       if(serial.open(QIODevice::ReadWrite))
       {
          ui->comboBox->addItem(serial.portName());
          serial.close();
       }
   }

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_MotorCalistir_clicked()
{

}

void MainWindow::on_BaglantiyiKes_clicked()
{

}

void MainWindow::Read_Data()
{
    QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {
        if(buf[0]=='a')
        {
            // QString str= ui-> textEdit->toPlainText();
            // str+=tr(buf);
            // ui->textEdit->clear();
            // ui->textEdit->append(str);
            QTextStream textStream(&file);
            QDateTime time;
            //ui->textEdit->clear();
            //ui->textEdit->append(textStream.readAll());
            textStream.readAll();
            textStream << time.currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
            textStream << " [TX] : " <<  buf << "\n";
        }
    }
    buf.clear();
}


void MainWindow::on_BaglantiyiKes_pressed()
{
    serial = new QSerialPort;
    serial->setPortName(ui->comboBox->currentText());
    serial ->setBaudRate(ui->comboBox_2->currentText().toInt());
    switch(ui->comboBox_3->currentIndex())
    {
    case 0: serial->setParity(QSerialPort::NoParity); break;
    default: break;
    }
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadWrite);
    ui->comboBox->setEnabled(false);
    ui->comboBox_2->setEnabled(false);
    ui->comboBox_3->setEnabled(false);
    ui->BaglantiyiKes->setEnabled(false);
    QObject::connect(serial, &QSerialPort::readyRead, this, &MainWindow::Read_Data);

}
