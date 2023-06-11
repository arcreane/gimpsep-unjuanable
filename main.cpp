//#include "canny.h"
//
////int thresholdValue1 = 270; //滞后性阈值1
////int kenelValueCanny = 4; //降噪内核值
////const int MaxKenelValueCanny = 10;
////const int MaxThresholdValue1 = 300;
////String srcAdressCanny;
//
//int main() {
//    string imageFilePath = "./picsou.bmp";
//    Canny(imageFilePath);
//    return 0;
//}

#include<iostream>  
#include <opencv2/core/core.hpp>  
#include <opencv2/highgui/highgui.hpp>  
#include <opencv2/imgproc/imgproc.hpp> 
#include <opencv2\imgproc\types_c.h>

using namespace cv;
using namespace std;

// Function declarations
void resizing(String imageFilePath);
void lighten(String imageFilePath);
void Canny(String ssrcAdress);
void performOperation(const String& imageFilePath);
void stitchImagesInDirectory(const std::string& directoryPath, const std::string& resultPath);

int main() {
    int choice;
    cout << "Select an option:" << endl;
    cout << "1. Resizing" << endl;
    cout << "2. Lighten" << endl;
    cout << "3. Canny Edge Detection" << endl;
    cout << "4. Dilate or erode" << endl;
    cout << "5. Sitching photos" << endl;
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    string imageFilePath;  // Declare the variable outside the switch statement
    string outputPath;
    int argc = 0;  // Initialize argc to 0

    switch (choice) {
    case 1:
        // Prompt for the image file path
        cout << "Enter the image file path: ";
        cin >> imageFilePath;

        // Call the resizing function
        resizing(imageFilePath);
        break;
    case 2:
         // Prompt for the image file path
        cout << "Enter the image file path: ";
        cin >> imageFilePath;

        // Call the lighten function
        lighten(imageFilePath);
        break;
    case 3:
        // Prompt for the image file path
        cout << "Enter the image file path: ";
        cin >> imageFilePath;

        // Call the Canny function
        Canny(imageFilePath);
        break;
    case 4:
        // Prompt for the image file path
        cout << "Enter the image file path: ";
        cin >> imageFilePath;

        // Call the performOperation function

        performOperation(imageFilePath);
        break;
    case 5:
        cout << "Enter the full path to the directory or file(s) to stitch: ";
        cin >> imageFilePath;

        cout << "Enter the full path for the output stitched image: ";
        cin >> outputPath;

        stitchImagesInDirectory(imageFilePath, outputPath);
        break;
    default:
        cout << "Invalid choice!" << endl;
        break;
    }

    return 0;
}
