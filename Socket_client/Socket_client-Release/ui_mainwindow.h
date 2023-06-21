/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QTextEdit *input_path;
    QLabel *label_1;
    QLabel *label_2;
    QTextEdit *output_path;
    QRadioButton *radioButton_x4;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QRadioButton *radioButton_x2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(792, 470);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(510, 185, 93, 28));
        pushButton->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        input_path = new QTextEdit(centralwidget);
        input_path->setObjectName(QString::fromUtf8("input_path"));
        input_path->setGeometry(QRect(200, 234, 491, 31));
        input_path->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label_1 = new QLabel(centralwidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(112, 238, 81, 21));
        label_1->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(107, 281, 91, 21));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        output_path = new QTextEdit(centralwidget);
        output_path->setObjectName(QString::fromUtf8("output_path"));
        output_path->setGeometry(QRect(200, 277, 491, 31));
        output_path->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        radioButton_x4 = new QRadioButton(centralwidget);
        radioButton_x4->setObjectName(QString::fromUtf8("radioButton_x4"));
        radioButton_x4->setGeometry(QRect(350, 190, 101, 19));
        radioButton_x4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(90, 60, 641, 31));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0,0,0);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-color: rgb(255, 0, 0);\n"
""));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(133, 103, 561, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0,0,0);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-color: rgb(255, 0, 0);\n"
""));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 144, 491, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0,0,0);\n"
"font: 10pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"border-color: rgb(255, 0, 0);\n"
""));
        radioButton_x2 = new QRadioButton(centralwidget);
        radioButton_x2->setObjectName(QString::fromUtf8("radioButton_x2"));
        radioButton_x2->setGeometry(QRect(210, 190, 115, 19));
        radioButton_x2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 0, 0);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 792, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\276\347\211\207", nullptr));
        label_1->setText(QCoreApplication::translate("MainWindow", "Input_path", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Output_path", nullptr));
        output_path->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">./result</p></body></html>", nullptr));
        radioButton_x4->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247\345\233\233\345\200\215x4", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\350\277\231\346\230\257\344\270\200\344\270\252\345\233\276\345\203\217\350\266\205\345\210\206\350\276\250\347\216\207APP\357\274\214\345\217\257\344\273\245\346\224\276\345\244\247\345\233\276\347\211\207\357\274\214\346\217\220\351\253\230\345\233\276\347\211\207\350\264\250\351\207\217\343\200\202\347\233\256\345\211\215\345\217\252\346\224\257\346\214\201x2\343\200\201x4\350\266\205\345\210\206", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Output_path\344\270\272\345\233\276\345\203\217\344\277\235\345\255\230\350\267\257\345\276\204\357\274\214\345\217\257\350\207\252\350\241\214\350\256\276\347\275\256\357\274\210\351\273\230\350\256\244\344\270\272APP\350\267\257\345\276\204\347\232\204result\346\226\207\344\273\266\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\233\276\347\211\207\346\257\224\350\276\203\345\244\247\357\274\210\345\273\272\350\256\256400x400\344\273\245\345\206\205\357\274\211\351\234\200\350\246\201\351\252\232\347\255\211\345\207\240\347\247\222\357\274\214\350\256\251\345\255\220\345\274\271\351\243\236\344\270\200\344\274\232~", nullptr));
        radioButton_x2->setText(QCoreApplication::translate("MainWindow", "\346\224\276\345\244\247\344\270\244\345\200\215x2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
