#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2\imgproc\types_c.h>

using namespace cv;
using namespace std;
//������ʼ��
int thresholdValue1 = 270;//�ͺ�����ֵ1
int kenelValueCanny = 4;//�����ں�ֵ
const static int MaxKenelValueCanny = 10;
const static int MaxThresholdValue1 = 300;
String imageFilePathCanny;

//�ص�����
static void callBackCanny(int, void*) {

	Mat srcImage = imread(imageFilePathCanny, 3);
	Mat dstImage, grayImage, denoiseImage, cannyImage;
	if (!srcImage.data) {
		cout << "ͼ���ȡ����";
		return;
	}

	//������srcImageͬ���ͺʹ�С�ľ��� 
	dstImage.create(srcImage.size(), srcImage.type());

	//��ԭͼ��ת��Ϊ�Ҷ�ͼ��  
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);

	//��˹�˲�����
	GaussianBlur(grayImage, denoiseImage, Size(kenelValueCanny * 2 + 1, kenelValueCanny * 2 + 1), 0, 0);

	//ʹ��Canny����
	Canny(denoiseImage, cannyImage, thresholdValue1, thresholdValue1 * 2 / 3, 3);

	//��dstImage�ڵ�����Ԫ������Ϊ0
	dstImage = Scalar::all(0);

	//��cannyImage��Ϊ���룬��ԭͼsrcImage����Ŀ��ͼdstImage��
	srcImage.copyTo(dstImage, cannyImage);

	//��ʾ
	imshow("ԭͼ", srcImage);
	imshow("Canny���ӱ�Ե���Ч��Ԥ����", dstImage);
	imwrite("E:/opencv/Canny.jpg", dstImage);
}

//����������
void Canny(String srcFilePathCanny) {

	imageFilePathCanny = srcFilePathCanny;

	namedWindow("Canny���ӱ�Ե���Ч��Ԥ����", WINDOW_AUTOSIZE);

	//����������
	createTrackbar("�ں�ֵ��", "Canny���ӱ�Ե���Ч��Ԥ����", &kenelValueCanny, MaxKenelValueCanny, callBackCanny);
	createTrackbar("��ֵһ��", "Canny���ӱ�Ե���Ч��Ԥ����", &thresholdValue1, MaxThresholdValue1, callBackCanny);

	//�ص�
	callBackCanny(kenelValueCanny, 0);
	callBackCanny(thresholdValue1, 0);

	waitKey(0);

}