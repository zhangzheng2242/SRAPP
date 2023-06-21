#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlDatabase>
#include<QSqlQuery>
#include <opencv2/opencv.hpp>
#include "sr.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Server : public QWidget
{
    Q_OBJECT

public:
    Server(QWidget *parent = nullptr);
    ~Server();

private slots:


    void receiveMessage();

private:
    Ui::Widget *ui;
    //声明两种套接字
    QTcpServer *tcpserver;
    QTcpSocket *tcpsocket;

    SR *SuperResolution;
    QByteArray jsonData;



    void sendImageResult(const cv::Mat &imageResult);

    QString LoginJudgment(const QString &password, const QString &username);
    void sendLoninResult(const QString &ret);

    QString SignUpJudgment(const QString &password, const QString &signupUsername);
    void sendSignUpResult(const QString &ret);

};
#endif // WIDGET_H
