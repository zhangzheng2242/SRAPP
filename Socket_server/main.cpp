#include "server.h"
#include<QDebug>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Server server;
    server.show();


    return a.exec();
}
