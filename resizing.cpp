#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;
int width;
int height;
String imageFilePathResizing;


void resizing(String imageFilePathResizing)
{
    Mat image = cv::imread(imageFilePathResizing);
    
    //Enter the height and width values
    cout << "Enter the width value: ";
    cin >> width;
    cout << "Enter the height value: ";
    cin >> height;
    Mat resized;
    resize(image, resized, cv::Size(width, height), cv::INTER_LINEAR);

    namedWindow("Resized Down by defining height and width", cv::WINDOW_NORMAL);
    imshow("Original Image", image);
    imshow("Resized Down by defining height and width", resized);
    waitKey(0);

    cv::destroyAllWindows();
}

