#include "signup.h"
#include "ui_signup.h"

SignUp::SignUp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    this->setFixedSize(500,360);
    this->setWindowTitle("图像超分APP1.0用户注册");
    //设置密码模式
    ui->Password->setEchoMode(QLineEdit::Password);
    ui->ConfirmPassword->setEchoMode(QLineEdit::Password);

}

SignUp::~SignUp()
{
    delete socket;
    delete ui;
}




void SignUp::on_pushButton_clicked()
{
    QString signupUsername = ui->SignUpUsername->text();
    QString password = ui->Password->text();
    QString confirmPassword = ui->ConfirmPassword->text();
    //判断用户名不为空
    if(signupUsername==NULL||password==NULL){
        QMessageBox::information(this, "用户名", "用户名或密码不能为空");
        return;
    }

    if(password!=confirmPassword){
        //两次输入密码是否一致
        QMessageBox::information(this, "注册失败", "两次密码输入不一致");
        ui->ConfirmPassword->clear();
    }else{
    //判断用户名是否存在  在服务器判断  给服务器发送 注册业务、用户名、密码
        //构建json文件
        // 创建 JSON 对象
        QJsonObject jsonObject;

        // 设置业务名称
        jsonObject["business_name"] = "SignUp";
        jsonObject["signupUsername"] = signupUsername;
        jsonObject["password"] = password;


        // 创建 JSON 文档并转换为 QByteArray
        QJsonDocument jsonDocument(jsonObject);
        QByteArray jsonData = jsonDocument.toJson();

        // 发送数据
        socket->write(jsonData);
        socket->flush();


    }


}
