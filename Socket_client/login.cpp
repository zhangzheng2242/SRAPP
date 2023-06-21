#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
LogIn::LogIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    this->setFixedSize(500,360);
    this->setWindowTitle("图像超分SRAPP1.0登录界面");
    //设置密码模式
    ui->password->setEchoMode(QLineEdit::Password);
//    socket = nullptr;

    socket = new QTcpSocket(this);
    QString ip = "10.16.89.0";
    QString port = "8888";
    socket->connectToHost(ip,port.toUInt());
    connect(socket,&QTcpSocket::readyRead,this,&LogIn::receiveMessage);

    //绑定enter键
    QShortcut *shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);
    // 连接activated信号到click  确认键
    connect(shortcut, &QShortcut::activated, ui->login, &QPushButton::click);

    connect(socket,&QTcpSocket::readyRead,this,&LogIn::receiveMessage);
}

LogIn::~LogIn()
{
    delete socket;
    delete signup;
    delete mainwindow;
    delete ui;
}

void LogIn::saveImage(const QString &SavePath, const QString &ImagePath,
                      const cv::Mat &ImageResult,const int &sr_scale)
{
    //获取文件名
    std::string Image_Path = ImagePath.toStdString();
    std::string::size_type iPos = Image_Path.find_last_of('/') + 1;
    //图像名+后缀 imagename.png
    std::string imagename = Image_Path.substr(iPos, ImagePath.length() - iPos);

    //获取图像名与后缀
    size_t dotIndex = imagename.find_last_of('.');
    // 提取文件名
    std::string name = imagename.substr(0, dotIndex);
    // 提取后缀名
    std::string extension = imagename.substr(dotIndex + 1);
    std::string scale ="_x"+std::to_string(sr_scale);

    const char *save_path =SavePath.toLatin1() ;
    //保存路径不存在创建路径
    if (_access(save_path, 0) == -1)
        {
            _mkdir(save_path);
        }

    cv::imwrite(std::string(save_path) + "/" +name+scale+"."+extension, ImageResult);
}

void LogIn::receiveMessage()
{
    //从通信套接字中取出内容  图片太大一次只能传输图片的一部分
    jsonData += socket->readAll();

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
                cv::Mat image_result = cv::imdecode(buffer, cv::IMREAD_COLOR);

                imshow("result",image_result);
                cv::waitKey(0);
                QString SavePath= mainwindow->getSavePath();
                QString ImagePath= mainwindow->getImagePath();
                int sr_scale = mainwindow->getSR_Scale();
                saveImage(SavePath,ImagePath,image_result,sr_scale);


                jsonData.clear();


            }else if (businessName == "LoninResult"){
                QString LoninResult = jsonObject["LoninResult"].toString();
                if(LoninResult=="LoginSuccess"){

                    this->hide();
                    this->mainwindow = new MainWindow();
                    this->mainwindow->socket = this->socket;
                    this->mainwindow->show();

                }else if(LoninResult=="InformationFailure"){
                    QMessageBox::information(this, "登录 ", "用户名不存在或密码错误");
                }else if(LoninResult =="LoninResult"){
                    QMessageBox::information(this, "infor", "系统错误");
                }
                jsonData.clear();
            }else if (businessName == "SignUpResult"){
                QString SignUpResult = jsonObject["SignUpResult"].toString();
                if(SignUpResult=="SignUpSuccess"){
                    QMessageBox::information(this->signup, "注册成功 ", "您已经完成注册，点击0k返回登录");
                    this->signup->close();
                    this->show();
                }else if(SignUpResult=="UsernameExists"){
                    QMessageBox::information(this->signup, "注册失败 ", "用户名已存在");
                }else if(SignUpResult=="SystemError"){
                    QMessageBox::information(this->signup, "infor", "系统错误");
                }
                jsonData.clear();
            }
     }
    }
}




void LogIn::on_login_clicked()
{
    //获得账号密码然后打包成json文件发送给服务器处理
    QString username = ui->username->text();
    QString password = ui->password->text();
    //receiveMessage里面要做服务器结果逻辑判断  连接数据库交给服务器
    //构建json文件
    // 创建 JSON 对象
    QJsonObject jsonObject;

    // 设置业务名称
    jsonObject["business_name"] = "LogIn";
    jsonObject["username"] = username;
    jsonObject["password"] = password;


    // 创建 JSON 文档并转换为 QByteArray
    QJsonDocument jsonDocument(jsonObject);
    QByteArray jsonData = jsonDocument.toJson();

    // 发送数据
    socket->write(jsonData);
    socket->flush();

}

void LogIn::on_signin_clicked()
{
    this->signup = new SignUp();
    //设置窗口阻塞
    this->signup->socket = this->socket;
    this->signup->setWindowModality(Qt::ApplicationModal);
    this->hide();
    this->signup->show();



}
