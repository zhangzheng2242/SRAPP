#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QCloseEvent>
#include <cstring>
#include <QTcpSocket>
#include <opencv2/opencv.hpp>
#include <QJsonObject>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QString getSavePath();
    QString getImagePath();
    int getSR_Scale();

public:
    QTcpSocket *socket;
protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void sendImageToServer(const cv::Mat &imageResult, const QString &business_name, const int SR_scale);


};
#endif // MAINWINDOW_H
