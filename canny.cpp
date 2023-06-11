#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2\imgproc\types_c.h>

using namespace cv;
using namespace std;
// Initialization
int thresholdValue1 = 270;//Hysteresis threshold1
int kenelValueCanny = 4;//Noise reduction kernel value
const static int MaxKenelValueCanny = 10;
const static int MaxThresholdValue1 = 300;
String imageFilePathCanny;

//Callback functions
static void callBackCanny(int, void*) {

	Mat srcImage = imread(imageFilePathCanny, 3);
	Mat dstImage, grayImage, denoiseImage, cannyImage;
	if (!srcImage.data) {
		cout << "Image read error";
		return;
	}

	//Create a matrix of the same type and size as srcImage 
	dstImage.create(srcImage.size(), srcImage.type());

	//Convert to grayscale image  
	cvtColor(srcImage, grayImage, CV_BGR2GRAY);

	//Gaussian filter noise reduction
	GaussianBlur(grayImage, denoiseImage, Size(kenelValueCanny * 2 + 1, kenelValueCanny * 2 + 1), 0, 0);

	//Using the Canny operator
	Canny(denoiseImage, cannyImage, thresholdValue1, thresholdValue1 * 2 / 3, 3);

	dstImage = Scalar::all(0);

	srcImage.copyTo(dstImage, cannyImage);  //Use cannyImage as a mask

	imshow("Orignal Image", srcImage);
	imshow("Canny operator detection results：", dstImage);
	imwrite("E:/opencv/Canny.jpg", dstImage);
}

//Create progress bar
void Canny(String srcFilePathCanny) {

	imageFilePathCanny = srcFilePathCanny;

	namedWindow("Canny operator detection results：", WINDOW_AUTOSIZE);

	createTrackbar("Kernel Value：", "Canny operator detection results：", &kenelValueCanny, MaxKenelValueCanny, callBackCanny);
	createTrackbar("Threshold I：", "Canny operator detection results：", &thresholdValue1, MaxThresholdValue1, callBackCanny);

	callBackCanny(kenelValueCanny, 0);
	callBackCanny(thresholdValue1, 0);

	waitKey(0);

}
