#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("图像超分SRAPP1.0");
    this->setFixedSize(800,400);
    //背景
    QString background = "./source/background.png";
    QString styleSheet = QString("background-image: url(%1);").arg(background);
    this->setStyleSheet(styleSheet);

    //默认选择x2模型
    ui->radioButton_x2->setChecked(true);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete socket;
}

QString MainWindow::getSavePath()
{
    QString SavePath=ui->output_path->document()->toPlainText();
    return SavePath;
}

QString MainWindow::getImagePath()
{
    QString ImagePath=ui->input_path->document()->toPlainText();
    return ImagePath;
}

int MainWindow::getSR_Scale()
{
    int sr_scale = 2;
    if (ui->radioButton_x2->isChecked()) {
        sr_scale = 2;

    }else if(ui->radioButton_x4->isChecked()) {
        sr_scale = 4;

    }
    return sr_scale;

}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("提示");
    msgBox.setText("您确定要退出SRApp吗？");
    msgBox.setIcon(QMessageBox::Question);

    msgBox.addButton(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);

    int ret = msgBox.exec();

    if(ret==QMessageBox::Yes){
        event->accept();
    }else{
        event->ignore();
    }
}


void MainWindow::on_pushButton_clicked()
{
        ui->input_path->setText("");
        QString ImagePath = QFileDialog::getOpenFileName(this,tr("打开文件"),"./",
                                     tr("Images(*.png *.bmp *.jpg)"));
        if(!ImagePath.isEmpty()){

            int sr_scale = getSR_Scale();

            ui->input_path->append(ImagePath);



            //获取保存路径
//            QString strText=ui->output_path->document()->toPlainText();
            cv::Mat img_in = cv::imread(ImagePath.toStdString());
            QString business_name = "image_sr";
            sendImageToServer(img_in, business_name, sr_scale);

        }
}

void MainWindow::sendImageToServer(const cv::Mat &imageResult, const QString &business_name, const int SR_scale){
    //将image转换为QByteArray
    std::vector<uchar> buffer;
    cv::imencode(".png", imageResult, buffer);
    QByteArray imageData(reinterpret_cast<const char*>(buffer.data()), buffer.size());

    //构建json文件
    // 创建 JSON 对象
    QJsonObject jsonObject;

    // 设置业务名称
    jsonObject["business_name"] = business_name;

    jsonObject["SR_scale"] = QString::number(SR_scale);

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




