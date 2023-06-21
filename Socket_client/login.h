#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include "mainwindow.h"
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QMessageBox>
#include<QDebug>
#include <QSqlError>
#include<QShortcut>
#include <QTcpSocket>
#include <opencv2/opencv.hpp>
#include <QJsonDocument>
#include <QJsonObject>

#include <cstring>
#include <direct.h>
#include <io.h>

#include"signup.h"

namespace Ui {
class LogIn;
}

class LogIn : public QWidget
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = nullptr);
    ~LogIn();
    void saveImage(const QString &SavePath, const QString &ImagePath,
                   const cv::Mat &ImageResult, const int &sr_scale);
public:
    QTcpSocket *socket;

private slots:
    //确认 enter键
//    void on_pushButton_clicked();
    void on_login_clicked();

    void on_signin_clicked();
    void receiveMessage();

private:
    Ui::LogIn *ui;
    MainWindow *mainwindow;
    SignUp *signup;

    QByteArray jsonData;
};

#endif // LOGIN_H
