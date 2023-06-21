#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include <QDebug>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QTcpSocket>
#include <QJsonObject>
#include <QJsonDocument>
namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
public:
    QTcpSocket *socket;

private slots:
    void on_pushButton_clicked();


private:
    Ui::SignUp *ui;

};

#endif // SIGNUP_H
