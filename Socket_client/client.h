#ifndef CLIENT_H
#define CLIENT_H

#include <QWidget>
#include <QTcpSocket>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <QByteArray >
#include <QJsonObject>
#include <QJsonDocument>

QT_BEGIN_NAMESPACE
namespace Ui { class client; }
QT_END_NAMESPACE

class client : public QWidget
{
    Q_OBJECT

public:
    client(QWidget *parent = nullptr);
    ~client();

private slots:
    void receiveMessage();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_selectImage_clicked();

private:
    Ui::client *ui;
    QTcpSocket *socket;
    void sendImageToServer(const cv::Mat &imageResult, const QString &business_name);
    QByteArray jsonData;

};
#endif // CLIENT_H
