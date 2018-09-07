#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("server");
    server = new QTcpServer(this);

    ui->lineEdit->setText("127.0.0.1");
    ui->lineEdit_2->setText("1234");

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(zhenting()));
    connect(server,SIGNAL(newConnection()),this,SLOT(newConnectionSlot()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::zhenting(){

    QString IP = ui->lineEdit->text();
    QString PORT = ui->lineEdit_2->text();

        if( !(server->listen(QHostAddress::Any,PORT.toInt())) )
                QMessageBox::warning(this,tr("warming"),tr("zhengting error"));
        ui->pushButton->setEnabled(0);

}




void Widget::newConnectionSlot(){
    sSocket = server->nextPendingConnection();
    QByteArray data = sSocket->readAll();
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(sendData()));
    connect(sSocket,SIGNAL(readyRead()),this,SLOT(receiveData()));
}

void Widget::receiveData(){
    current_date_time = QDateTime::currentDateTime();
    QString str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    QByteArray data = sSocket->readAll();
    ui->textBrowser->append("client "+str_date_time+"\n"+data);
}


void Widget::sendData(){
     current_date_time = QDateTime::currentDateTime();
    QString str_date_time = current_date_time.toString("yyyy-MM-dd hh:mm:ss");
    QByteArray dd = ui->lineEdit_3->text().toLatin1();
    sSocket->write(dd);
    sSocket->flush();
    ui->textBrowser->append("You "+str_date_time+"\n"+dd);
}


