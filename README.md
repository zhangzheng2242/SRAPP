### 一、SRAPP项目是什么?
#### 该项目算法优化背景为医学内窥镜图像超分辨（有降噪效果），解决内窥镜图像分辨率不足的问题，提高图像的细节和清晰度，从而可以改善医生的观察和诊断能力并更准确地确定病变位置并做出正确的诊断。
##### 模型大小初始为63.94MB优化到1.02MB，适合深度学习超分辨降噪算法轻量化部署。
###### 内窥镜图像可能引起不适，readme只展示了常规图像超分结果。内窥镜图像在 ./内窥镜图像超分结果 文件夹中。

一个基于c++、QT整合了轻量化图像超分辨率深度学习模型的APP项目。可x2、x4放大图片分辨率（x2超分 输入400x400图片可以得到800x800图片），使低分辨率的图像更加清晰。

在显卡GPU支持下，可输入1080p图片超分为4K图像。显存占用6G

后续还可以整合其他深度学习模型如图像分类、目标检测、图像分割等等。


### 二、所用环境配置

##### 1、Qt 5.14.2

##### 2、OpenCV 4.7.0

##### 3、libtorch 1.7.0

### 三、项目所包含内容

##### 1、socket网络编程，TCP，客户端、服务端业务逻辑

##### 2、QT界面

##### 3、数据库，注册登录功能

##### 4、图像超分辨率深度学习模型c++部署

##### 5、OpenCV图像处理 Mat 转 深度学习tensor

### 四、效果展示

##### 1、客户端登录、注册界面
<img src="./images/login.png"  width=250 height=200> <img src="./images/signUp.png" width=250 height=200>

##### 2、图像超分界面
点击选择图片按钮可以选择图片（中文路径会报错）

可选择超分大小 x2 放大两倍（400x400变为800x800）  x4放大4倍（400x400变为1600x1600）

也可以自己更改图像保存路径 Output_path

Input_path为你上次选择图片的路径

<img src="./images/APP.png"  width=390 height=200>

##### 3、图像超分效果（左边为输入图片，右边为超分输出图片）
温馨提示：放大看超分辨效果更加明显
###### 3.1 image one
<img src="./images/test1.jpg"  width=224 height=208> <img src="./images/test1_x4.jpg"  width=224 height=208>
###### 3.2 image two
<img src="./images/test2.png"  width=258 height=286> <img src="./images/test2_x4.png"  width=258 height=286>
###### 3.3 image three
<img src="./images/test3.png"  width=250 height=250> <img src="./images/test3_x4.png"  width=250 height=250>
###### 3.4 image four
<img src="./images/test4.png"  width=250 height=250> <img src="./images/test4_x4.png"  width=250 height=250>
###### 3.5 image five
<img src="./images/test5.png"  width=250 height=250> <img src="./images/test5_x4.png"  width=250 height=250>

超分效果很棒

<img src="./images/nice.jpg"  width=208 height=208> <img src="./images/nice_x4.jpg"  width=208 height=208>

<img src="./images/star.jpg"  width=300 height=300> <img src="./images/star_x4.jpg"  width=300 height=300>

超分图片略有失真请见谅

### 五、联系作者

可直接github交流

也可联系本人QQ：1791866021

24h超长待机时间
