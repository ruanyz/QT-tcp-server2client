#include "widget.h"
#include <QApplication>
#include <client.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    client c;
    c.show();


    return a.exec();
}
