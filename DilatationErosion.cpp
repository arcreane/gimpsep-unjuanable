#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;



void performOperation(const String& imageFilePath)
{
    cv::Mat inputImage = cv::imread(imageFilePath, cv::IMREAD_COLOR);
    if (inputImage.empty())
    {
        std::cout << "Failed to load the input image." << std::endl;
        return;
    }

    int operation, erosionSize;
    std::cout << "Enter 1 to dilate the image or 2 to erode the image: ";
    std::cin >> operation;
    std::cout << "Enter the erosion size: ";
    std::cin >> erosionSize;

    cv::Mat outputImage;
    cv::Mat structuringElement = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(2 * erosionSize + 1, 2 * erosionSize + 1),
                                                           cv::Point(erosionSize, erosionSize));


    if (operation == 1) // Dilate
    {
        cv::dilate(inputImage, outputImage, structuringElement);
    }
    else if (operation == 2) // Erode
    {
        cv::erode(inputImage, outputImage, structuringElement);
    }
    else
    {
        std::cout << "Invalid operation. Please choose 1 for dilate or 2 for erode." << std::endl;
        return;
    }

    cv::imshow("Output Image", outputImage);
    cv::waitKey(0);
}
