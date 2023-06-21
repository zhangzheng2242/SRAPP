/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QPushButton *pushButton;
    QLineEdit *ip;
    QLineEdit *port;
    QTextEdit *receive;
    QTextEdit *send;
    QLabel *label;
    QPushButton *pushButton_2;
    QPushButton *selectImage;

    void setupUi(QWidget *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QString::fromUtf8("client"));
        client->resize(800, 600);
        QFont font;
        font.setPointSize(16);
        client->setFont(font);
        pushButton = new QPushButton(client);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 60, 81, 31));
        ip = new QLineEdit(client);
        ip->setObjectName(QString::fromUtf8("ip"));
        ip->setGeometry(QRect(130, 60, 151, 31));
        port = new QLineEdit(client);
        port->setObjectName(QString::fromUtf8("port"));
        port->setGeometry(QRect(330, 60, 121, 31));
        port->setFont(font);
        receive = new QTextEdit(client);
        receive->setObjectName(QString::fromUtf8("receive"));
        receive->setGeometry(QRect(90, 130, 221, 131));
        send = new QTextEdit(client);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(90, 280, 221, 131));
        label = new QLabel(client);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 130, 61, 31));
        pushButton_2 = new QPushButton(client);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 380, 81, 31));
        selectImage = new QPushButton(client);
        selectImage->setObjectName(QString::fromUtf8("selectImage"));
        selectImage->setGeometry(QRect(540, 360, 171, 51));

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QWidget *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "client", nullptr));
        pushButton->setText(QCoreApplication::translate("client", "\350\277\236\346\216\245", nullptr));
        ip->setText(QCoreApplication::translate("client", "127.0.0.1", nullptr));
        port->setText(QCoreApplication::translate("client", "8888", nullptr));
        label->setText(QCoreApplication::translate("client", "\346\216\245\346\224\266", nullptr));
        pushButton_2->setText(QCoreApplication::translate("client", "\345\217\221\351\200\201", nullptr));
        selectImage->setText(QCoreApplication::translate("client", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
