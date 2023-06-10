#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2\imgproc\types_c.h>
#include <iostream>

using namespace std;
using namespace cv;


double alpha; // Control Contrast, if alpha = 1, the image is orignal image, Interval[0.0, 2.0] in usual.
int beta;  // Control brightness.
String imageFilePathLighten;

void lighten(String imageFilePathLighten)
{
    // Read user-supplied images
    Mat image = imread(imageFilePathLighten);
    //Pixel value initialization
    Mat new_image = Mat::zeros(image.size(), image.type());

    // Enter the value alpha and bete
    cout << " Linear Transforms " << endl;
    cout << "-------------------------" << endl;
    cout << "Enter the alpha value [1.0-3.0]: ";
    cin >> alpha;
    cout << "Enter the beta value [0-100]: ";
    cin >> beta;

    //Execution of operations of the formula g(x,y) = alpha*f(x,y) + beta
    for (int y = 0; y < image.rows; y++)
    {
        for (int x = 0; x < image.cols; x++)
        {
            for (int c = 0; c < 3; c++)
            {
                new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha * (image.at<Vec3b>(y, x)[c]) + beta);
            }
        }
    }

    // Create the window for showing the image
    namedWindow("Original Image", 1);
    namedWindow("New Image", 1);

    // Show image
    imshow("Original Image", image);
    imshow("New Image", new_image);

    waitKey();
}
