#include <opencv2/opencv.hpp>
#include <iostream>


using namespace std;
using namespace cv;
int width;
int height;
String imageFilePathResizing;


void resizing(String imageFilePathResizing)
{
    // Read the image using imread function
    Mat image = cv::imread(imageFilePathResizing);
    
    // let's downscale the image using new width and height
    cout << "Enter the width value: ";
    cin >> width;
    cout << "Enter the height value: ";
    cin >> height;
    //int down_width = 300;
    //int down_height = 200;
    Mat resized_down;
    // resize down
    resize(image, resized_down, cv::Size(width, height), cv::INTER_LINEAR);
    // let's upscale the image using new width and height
    //int up_width = 600;
    //int up_height = 400;
    //Mat resized_up;
    //// resize up
    //resize(image, resized_up, cv::Size(up_width, up_height), cv::INTER_LINEAR);
    // Display Images and press any key to continue
    namedWindow("Resized Down by defining height and width", cv::WINDOW_NORMAL);
    imshow("Original Image", image);
    imshow("Resized Down by defining height and width", resized_down);
    waitKey(0);
    //namedWindow("Resized Up image by defining height and width", cv::WINDOW_NORMAL);
    //cv::imshow("Resized Up image by defining height and width", resized_up);
    //cv::waitKey(0);

    cv::destroyAllWindows();
}

