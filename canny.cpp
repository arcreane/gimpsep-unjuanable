#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2\imgproc\types_c.h>

using namespace cv;
using namespace std;
//参数初始化
int thresholdValue1 = 270;//滞后性阈值1
int kenelValueCanny = 4;//降噪内核值
const static int MaxKenelValueCanny = 10;
const static int MaxThresholdValue1 = 300;
String imageFilePathCanny;

//回调函数
static void callBackCanny(int, void*) {

	Mat srcImage = imread(imageFilePathCanny, 3);
	Mat dstImage, grayImage, denoiseImage, cannyImage;
	if (!srcImage.data) {
		cout << "图像读取出错";
		return;
	}

	//创建与srcImage同类型和大小的矩阵 
	dstImage.create(srcImage.size(), srcImage.type());

	//将原图像转换为灰度图像  
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);

	//高斯滤波降噪
	GaussianBlur(grayImage, denoiseImage, Size(kenelValueCanny * 2 + 1, kenelValueCanny * 2 + 1), 0, 0);

	//使用Canny算子
	Canny(denoiseImage, cannyImage, thresholdValue1, thresholdValue1 * 2 / 3, 3);

	//将dstImage内的所有元素设置为0
	dstImage = Scalar::all(0);

	//以cannyImage作为掩码，将原图srcImage拷到目标图dstImage中
	srcImage.copyTo(dstImage, cannyImage);

	//显示
	imshow("原图", srcImage);
	imshow("Canny算子边缘检测效果预览：", dstImage);
	imwrite("E:/opencv/Canny.jpg", dstImage);
}

//创建进度条
void Canny(String srcFilePathCanny) {

	imageFilePathCanny = srcFilePathCanny;

	namedWindow("Canny算子边缘检测效果预览：", WINDOW_AUTOSIZE);

	//创建进度条
	createTrackbar("内核值：", "Canny算子边缘检测效果预览：", &kenelValueCanny, MaxKenelValueCanny, callBackCanny);
	createTrackbar("阈值一：", "Canny算子边缘检测效果预览：", &thresholdValue1, MaxThresholdValue1, callBackCanny);

	//回调
	callBackCanny(kenelValueCanny, 0);
	callBackCanny(thresholdValue1, 0);

	waitKey(0);

}