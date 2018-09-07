#include "client.h"
#include "ui_client.h"
#include <QTime>

client::client(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::client)
{
    ui->setupUi(this);
    this->setWindowTitle("client");
    cSocket = new QTcpSocket();

    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("1234");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(linkSlot()));

}

client::~client()
{
    delete ui;
}



void client::linkSlot(){
    QString IP = ui->lineEdit->text();
    QString PORT  = ui->lineEdit_2->text();
    cSocket->connectToHost("127.0.0.1",PORT.toInt());
    ui->pushButton->setEnabled(0);
    connect(cSocket,SIGNAL(readyRead()),this,SLOT(receiveData()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(sendData()));
}

void client::receiveData(){
     current_date_time = QDateTime::currentDateTime();
    QString str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    QString data = cSocket->readAll();
     ui->textBrowser->append("server "+str_date_time+"\n"+data);
}

void client::sendData(){
     current_date_time = QDateTime::currentDateTime();
    QString str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    QByteArray dd = ui->lineEdit_3->text().toLatin1();
    cSocket->write(dd);
    cSocket->flush();
    ui->textBrowser->append("You "+str_date_time+"\n"+dd);
}



