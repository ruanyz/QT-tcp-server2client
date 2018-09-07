#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QMessageBox>
#include <QDebug>
#include <QDateTime>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private:
    Ui::Widget *ui;
    QTcpServer  *server;
    QTcpSocket  *sSocket;
    QDateTime current_date_time;


public slots:
    void newConnectionSlot();
    void sendData();
    void receiveData();
    void zhenting();

};

#endif // WIDGET_H
