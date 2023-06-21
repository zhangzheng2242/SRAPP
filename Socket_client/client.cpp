#include "client.h"
#include "ui_client.h"

client::client(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);


}

client::~client()
{

    delete socket;
    delete ui;

}


void client::on_pushButton_clicked()
{
    socket = new QTcpSocket(this);
    QString ip = "127.0.0.1";
    QString port = "8888";
    socket->connectToHost(ip,port.toUInt());
    connect(socket,&QTcpSocket::readyRead,this,&client::receiveMessage);

}

void client::receiveMessage()
{


    jsonData += socket->readAll();


//     QByteArray jsonData = socket->readAll();
     ui->receive->append("server: "+jsonData);

     QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);


     if (!jsonDocument.isNull()) {

         if (jsonDocument.isObject()) {
             QJsonObject jsonObject = jsonDocument.object();

             // 提取 JSON 数据中的字段
             QString businessName = jsonObject["business_name"].toString();

            if (businessName == "image_result"){

                //图片转为cv::Mat
                QString base64ImageData = jsonObject["image_data"].toString();

                QByteArray imageData = QByteArray::fromBase64(base64ImageData.toLatin1());
                std::vector<uchar> buffer(imageData.begin(), imageData.end());
                cv::Mat image = cv::imdecode(buffer, cv::IMREAD_COLOR);

                imshow("result",image);
                cv::waitKey(0);
                jsonData.clear();


            }

         }
     }



}

void client::on_pushButton_2_clicked()
{
    QString str = ui->send->toPlainText();
    socket->write(str.toUtf8());

}

void client::on_selectImage_clicked()
{
    QString ImagePath = QFileDialog::getOpenFileName(this,tr("打开文件"),"./",
                                 tr("Images(*.png *.bmp *.jpg)"));
    if(!ImagePath.isEmpty()){
        cv::Mat img_in = cv::imread(ImagePath.toStdString());
        QString business_name = "image_sr";
        sendImageToServer(img_in, business_name);
    }

}

void client::sendImageToServer(const cv::Mat &imageResult, const QString &business_name){
    //将image转换为QByteArray
    std::vector<uchar> buffer;
    cv::imencode(".png", imageResult, buffer);
    QByteArray imageData(reinterpret_cast<const char*>(buffer.data()), buffer.size());

    //构建json文件
    // 创建 JSON 对象
    QJsonObject jsonObject;

    // 设置业务名称
    jsonObject["business_name"] = business_name;

    jsonObject["SR_scale"] = "4";

    // 设置图片数据（图像数据存储在 QByteArray 中）

    QString base64ImageData = QString::fromLatin1(imageData.toBase64());
    jsonObject["image_data"] = base64ImageData;

    // 创建 JSON 文档并转换为 QByteArray
    QJsonDocument jsonDocument(jsonObject);
    QByteArray jsonData = jsonDocument.toJson();

    // 发送数据
    socket->write(jsonData);
    socket->flush();
}

