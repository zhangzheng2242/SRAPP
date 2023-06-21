#include "login.h"
#include <QApplication>
#include <QTcpSocket>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    QTcpSocket *socket = new QTcpSocket;
//    QString ip = "127.0.0.1";
//    QString port = "8888";
//    socket->connectToHost(ip,port.toUInt());

    LogIn login;
//    login.socket = socket;
    login.show();
    return a.exec();
}
