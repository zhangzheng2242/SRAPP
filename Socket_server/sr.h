#ifndef SR_H
#define SR_H

#include<iostream>
#include<opencv2/opencv.hpp>
#include <time.h>
#include<cstring>
#undef slots
#undef UNICODE   //这个一定要加，否则会编译错误
#include <torch/torch.h>
#include <torch/script.h> // 引入libtorch头文件
#define slots Q_SLOTS

#include <direct.h>
#include <io.h>

class SR
{
public:
    SR();
    cv::Mat SR_func(const cv::Mat &Image_in, const int &SR_scale);
};

#endif // SR_H
