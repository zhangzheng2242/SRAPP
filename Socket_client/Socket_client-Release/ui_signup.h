/********************************************************************************
** Form generated from reading UI file 'signup.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUP_H
#define UI_SIGNUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SignUp
{
public:
    QLineEdit *SignUpUsername;
    QLabel *username_label;
    QLabel *password_label;
    QLineEdit *Password;
    QLabel *ConfirmPassword_label;
    QLineEdit *ConfirmPassword;
    QPushButton *pushButton;

    void setupUi(QWidget *SignUp)
    {
        if (SignUp->objectName().isEmpty())
            SignUp->setObjectName(QString::fromUtf8("SignUp"));
        SignUp->resize(500, 360);
        SignUpUsername = new QLineEdit(SignUp);
        SignUpUsername->setObjectName(QString::fromUtf8("SignUpUsername"));
        SignUpUsername->setGeometry(QRect(220, 80, 171, 31));
        username_label = new QLabel(SignUp);
        username_label->setObjectName(QString::fromUtf8("username_label"));
        username_label->setGeometry(QRect(120, 80, 81, 31));
        QFont font;
        font.setPointSize(16);
        username_label->setFont(font);
        password_label = new QLabel(SignUp);
        password_label->setObjectName(QString::fromUtf8("password_label"));
        password_label->setGeometry(QRect(120, 130, 81, 31));
        password_label->setFont(font);
        Password = new QLineEdit(SignUp);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(220, 130, 171, 31));
        ConfirmPassword_label = new QLabel(SignUp);
        ConfirmPassword_label->setObjectName(QString::fromUtf8("ConfirmPassword_label"));
        ConfirmPassword_label->setGeometry(QRect(100, 180, 111, 31));
        ConfirmPassword_label->setFont(font);
        ConfirmPassword = new QLineEdit(SignUp);
        ConfirmPassword->setObjectName(QString::fromUtf8("ConfirmPassword"));
        ConfirmPassword->setGeometry(QRect(220, 180, 171, 31));
        pushButton = new QPushButton(SignUp);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 230, 80, 40));
        pushButton->setFont(font);

        retranslateUi(SignUp);

        QMetaObject::connectSlotsByName(SignUp);
    } // setupUi

    void retranslateUi(QWidget *SignUp)
    {
        SignUp->setWindowTitle(QCoreApplication::translate("SignUp", "Form", nullptr));
        username_label->setText(QCoreApplication::translate("SignUp", "\347\224\250\346\210\267\345\220\215", nullptr));
        password_label->setText(QCoreApplication::translate("SignUp", "\345\257\206  \347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        Password->setToolTip(QCoreApplication::translate("SignUp", "<html><head/><body><p>\345\257\206\347\240\201</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ConfirmPassword_label->setText(QCoreApplication::translate("SignUp", "\347\241\256\350\256\244\345\257\206\347\240\201", nullptr));
#if QT_CONFIG(tooltip)
        ConfirmPassword->setToolTip(QCoreApplication::translate("SignUp", "<html><head/><body><p>\347\241\256\350\256\244\345\257\206\347\240\201</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pushButton->setText(QCoreApplication::translate("SignUp", "\347\241\256\350\256\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SignUp: public Ui_SignUp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUP_H
