#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>
#include <QDateTime>

namespace Ui {
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = 0);
    ~client();

private:
    Ui::client *ui;
    QTcpSocket *cSocket;
    QDateTime current_date_time;

public slots:
    void linkSlot();
    void receiveData();
    void sendData();

};

#endif // CLIENT_H
