#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

void stitchImages(const std::vector<std::string>& imageNames, const std::string& resultPath)
{
    std::vector<cv::Mat> images;
    for (const auto& imageName : imageNames)
    {
        cv::Mat image = cv::imread(imageName);
        if (image.empty())
        {
            std::cout << "Failed to load image: " << imageName << std::endl;
            return;
        }
        images.push_back(image);
    }

    cv::Mat result;
    cv::Ptr<cv::Stitcher> stitcher = cv::Stitcher::create();
    cv::Stitcher::Status status = stitcher->stitch(images, result);

    if (status == cv::Stitcher::OK)
    {
        cv::imwrite(resultPath, result);
        std::cout << "Stitched image saved successfully: " << resultPath << std::endl;
    }
    else
    {
        std::cout << "Image stitching failed with error code: " << status << std::endl;
    }
}

void stitchImagesInDirectory(const std::string& directoryPath, const std::string& resultPath)
{
    std::vector<std::string> imageNames;

    cv::glob(directoryPath, imageNames);
    if (imageNames.empty())
    {
        std::cout << "No image files found in the directory." << std::endl;
        return;
    }

    stitchImages(imageNames, resultPath);
}



