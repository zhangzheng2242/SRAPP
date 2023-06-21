#include "server.h"
#include "ui_server.h"
#include <QDebug>

Server::Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tcpserver=nullptr;
    tcpsocket=nullptr;
    //创建监听套接字
    tcpserver=new QTcpServer(this);//指定父对象 回收空间

    //bind+listen
    tcpserver->listen(QHostAddress::Any,8888);//绑定当前网卡所有的ip 绑定端口 也就是设置服务器地址和端口号

    //服务器建立连接
    connect(tcpserver,&QTcpServer::newConnection,[=](){
        //取出连接好的套接字
        tcpsocket = tcpserver->nextPendingConnection();

        //获得通信套接字的控制信息
        QString ip = tcpsocket->peerAddress().toString();//获取连接的 ip地址
        quint16 port = tcpsocket->peerPort();//获取连接的 端口号
        QString temp = QString("[%1:%2] The client connection is successful. ").arg(ip).arg(port);
        //显示连接成功
        ui->receive->setText(temp.toUtf8());

        //接收信息  必须放到连接中的槽函数 不然tcpsocket就是一个野指针
        connect(tcpsocket,&QTcpSocket::readyRead,this,&Server::receiveMessage);
    });

    SuperResolution = new SR;





}

Server::~Server()
{
    delete SuperResolution;
    delete tcpsocket;
    delete tcpserver;
    delete ui;

}

void Server::receiveMessage(){
    //从通信套接字中取出内容  图片太大一次只能传输图片的一部分
    jsonData +=tcpsocket->readAll();
     //在编辑区域显示

    //读取的信息处理业务逻辑
    //operation:登录、注册、超分
    //body: 登录（账号&密码）、注册（用户名&密码&确认密码）、超分（超分大小、图片数据）
    //对应返回： 登录（登录成功、用户名或密码错误）、注册（用户名已存在、注册成功）、超分（返回图片结果）

    //解析客户端发来的json文件信息

    // 解析 JSON 数据
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonData);
    if (!jsonDocument.isNull()) {
        if (jsonDocument.isObject()) {
            ui->receive->append("client: "+jsonData);//不用settext 这样会覆盖之前的消息
            QJsonObject jsonObject = jsonDocument.object();

            // 提取 JSON 数据中的字段
            QString businessName = jsonObject["business_name"].toString();
            // ...

            // 进行相应的业务处理
            if (businessName == "image_sr") {
                // 处理图像数据
                qDebug()<<"image_sr";
                QString base64ImageData = jsonObject["image_data"].toString();

                int sr_scale = jsonObject["SR_scale"].toString().toInt();

                QByteArray imageData = QByteArray::fromBase64(base64ImageData.toLatin1());
                std::vector<uchar> buffer(imageData.begin(), imageData.end());
                cv::Mat image = cv::imdecode(buffer, cv::IMREAD_COLOR);



                cv::Mat img_result = SuperResolution->SR_func(image, sr_scale);


                sendImageResult(img_result);

                jsonData.clear();

            }
            else if (businessName == "LogIn") {
                QString password = jsonObject["password"].toString();
                QString username = jsonObject["username"].toString();
                //作登录逻辑判断
                QString ret = LoginJudgment(password, username);
                sendLoninResult(ret);
                jsonData.clear();
            }else if(businessName == "SignUp"){
                QString password = jsonObject["password"].toString();
                QString signupUsername = jsonObject["signupUsername"].toString();
                QString ret = SignUpJudgment(password, signupUsername);
                sendSignUpResult(ret);
                jsonData.clear();
             }
            // ...
        }
    }




}

void Server::sendImageResult(const cv::Mat &imageResult){
    //将image转换为QByteArray
    std::vector<uchar> buffer;
    cv::imencode(".png", imageResult, buffer);
    QByteArray imageData(reinterpret_cast<const char*>(buffer.data()), buffer.size());

    //构建json文件
    // 创建 JSON 对象
    QJsonObject jsonObject;

    // 设置业务名称
    jsonObject["business_name"] = "image_result";

    // 设置图片数据（图像数据存储在 QByteArray 中）

    QString base64ImageData = QString::fromLatin1(imageData.toBase64());
    jsonObject["image_data"] = base64ImageData;

    // 创建 JSON 文档并转换为 QByteArray
    QJsonDocument jsonDocument(jsonObject);
    QByteArray jsonData = jsonDocument.toJson();

    ui->send->append("send: "+jsonData);
    tcpsocket->write(jsonData);
    tcpsocket->flush();


}

QString Server::LoginJudgment(const QString &password, const QString &username)
{
    QString ret = "SystemError";
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mysql"); //不是Database,记得别填错
    db.setUserName("root");
    db.setPassword("123456");
    //验证数据库是否连接成功
    bool ok = db.open();
    if (ok){

        QSqlQuery query(db);

        QString queryStr = "SELECT COUNT(*) FROM user WHERE username = :username AND password = :password";
        queryStr.replace(":username", "'"+username+"'");
        queryStr.replace(":password", "'"+password+"'");
        query.prepare(queryStr);

        qDebug()<<username;
        qDebug()<<password;
        qDebug()<<query.lastQuery();

        if (query.exec() && query.next()) {
            int count = query.value(0).toInt();

            if (count > 0) {
                // 用户名和密码匹配，执行登录逻辑
                ret =  "LoginSuccess" ;

            } else {
                //用户名不存在或密码错误
               ret =  "InformationFailure";
            }


        }
    }


    db.close();

    return ret ;

}

void Server::sendLoninResult(const QString &ret)
{
    //构建json文件
    // 创建 JSON 对象
    QJsonObject jsonObject;

    // 设置业务名称
    jsonObject["business_name"] = "LoninResult";
    jsonObject["LoninResult"] = ret;



    // 创建 JSON 文档并转换为 QByteArray
    QJsonDocument jsonDocument(jsonObject);
    QByteArray jsonData = jsonDocument.toJson();

    ui->send->append("send: "+jsonData);
    // 发送数据
    tcpsocket->write(jsonData);
    tcpsocket->flush();

}

QString Server::SignUpJudgment(const QString &password, const QString &signupUsername)
{
    QString ret = "SystemError";

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("mysql"); //不是Database,记得别填错
    db.setUserName("root");
    db.setPassword("123456");
    //验证数据库是否连接成功
    bool ok = db.open();
    if (ok){

        QSqlQuery query(db);

        QString queryStr = "insert into user(username,password) values(:username,:password)";
        queryStr.replace(":username", "'"+signupUsername+"'");
        queryStr.replace(":password", "'"+password+"'");
        query.prepare(queryStr);

        qDebug()<<signupUsername;
        qDebug()<<password;
        qDebug()<<query.lastQuery();

        if (query.exec()) {
            ret = "SignUpSuccess";


        }else{
            ret =  "UsernameExists";
        }


    }


    db.close();

    return ret;

}

void Server::sendSignUpResult(const QString &ret)
{
    //构建json文件
    // 创建 JSON 对象
    QJsonObject jsonObject;

    // 设置业务名称
    jsonObject["business_name"] = "SignUpResult";
    jsonObject["SignUpResult"] = ret;

    // 创建 JSON 文档并转换为 QByteArray
    QJsonDocument jsonDocument(jsonObject);
    QByteArray jsonData = jsonDocument.toJson();

    ui->send->append("send: "+jsonData);
    // 发送数据
    tcpsocket->write(jsonData);
    tcpsocket->flush();

}



