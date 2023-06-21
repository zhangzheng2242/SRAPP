#include "sr.h"

SR::SR()
{

}

cv::Mat SR::SR_func(const cv::Mat &Image_in, const int &SR_scale){

    //OpenCV读取的都是BGR格式，通常需要转成RGB的
    cv::Mat img;
    cv::cvtColor(Image_in , img , cv::COLOR_BGR2RGB);

    //将Mat数据转为Tensor张量数据
    std::vector<int64_t> sizes = {img.rows, img.cols, 3 };
    torch::TensorOptions option(torch::kByte);
    torch::Tensor tensor_image = torch::from_blob(img.data, sizes, option);

    //对应preprocess

    //维度换位，来满足模型的输入，就是1X400X400X3 变成 1X3X400X400  BCHW
    tensor_image = tensor_image.permute({2, 0, 1 });

//    cout<<tensor_image<<endl;  // 1, 3,400,400
    tensor_image = tensor_image.toType(torch::kFloat);
    // Normalization
    tensor_image = tensor_image.div(255.0);
    tensor_image = tensor_image.unsqueeze(0);



    //加载模型
    at::string model_path;
    if(SR_scale==2){
        model_path = "./model-11-x2.pt";

    }else if(SR_scale==4){
        model_path = "./model-x4.pt";
    }
    torch::jit::script::Module module;
    module = torch::jit::load(model_path);  //加载模型
    module.eval();
    //模型推理
    std::vector<torch::jit::IValue> inputs;
    inputs.push_back(tensor_image);

    clock_t start, finish;
    start = clock();

    at::Tensor output = module.forward(inputs).toTensor();


    finish = clock();

    std::cout <<std::endl<<"the time cost is:" << double(finish - start) / CLOCKS_PER_SEC<<std::endl;

    //       tensor结果转为cv图片
    //sequeeze trans tensor shape from 1*C*H*W to C*H*W
    //permute C*H*W to H*W*C   维度转换一定要加.contiguous() 保证内存的连续性
    output = output.squeeze(0);

    output = output.detach().permute({1, 2, 0}).contiguous();

    //在处理前对cvmat中的值做了归一化，所以现在要*255恢复，同时对于不在0-255范围内的数据，需要做限制
    output = output.mul(255.0).clamp(0.0, 255.0).to(torch::kU8);

    int frame_h , frame_w;
    frame_h = output.size(0);
    frame_w = output.size(1);

    cv::Mat resultImg(cv::Size(frame_w,frame_h),CV_8UC3,output.data_ptr());
    //copy the data from out_tensor to resultImg
//    std::memcpy((void *) resultImg.data, output.data_ptr(), sizeof(torch::kU8) * output.numel());
    cv::Mat output_img;

    cv::cvtColor(resultImg, output_img, cv::COLOR_RGB2BGR);

    return output_img;
}
