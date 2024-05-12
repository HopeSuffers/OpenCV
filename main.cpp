#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

/**
 * Adds salt and pepper noise to an image.
 *
 * @param srcArr Reference to the input/output image (cv::Mat).
 * @param pa Fraction of image pixels to affect with pepper noise.
 * @param pb Fraction of image pixels to affect with salt noise.
 */
void AddSaltAndPepperNoise(cv::Mat &srcArr, float pa, float pb)
{
    // Ensure the input image is of type CV_8UC1
    if (srcArr.type() != CV_8UC1) {
        throw std::invalid_argument("Input image must be of type CV_8UC1");
    }

    static cv::RNG rng(cv::getCPUTickCount());  // RNG initialized with a varying seed

    int totalPixels = srcArr.rows * srcArr.cols;
    int pepperCount = static_cast<int>(totalPixels * pa);
    int saltCount = static_cast<int>(totalPixels * pb);

    // Add pepper noise (dark spots)
    for (int i = 0; i < pepperCount; ++i) {
        int row = rng.uniform(0, srcArr.rows);
        int col = rng.uniform(0, srcArr.cols);
        srcArr.at<uchar>(row, col) = 0;
    }

    // Add salt noise (bright spots)
    for (int i = 0; i < saltCount; ++i) {
        int row = rng.uniform(0, srcArr.rows);
        int col = rng.uniform(0, srcArr.cols);
        srcArr.at<uchar>(row, col) = 255;
    }
}

bool initializeCamera(cv::VideoCapture &cap, int deviceID = 0, int apiID = cv::CAP_ANY)
{
    // Open the camera using the specified device ID and API
    cap.open(deviceID, apiID);
    // Check if the camera was opened successfully
    if (!cap.isOpened())
    {
        std::cerr << "ERROR! Unable to open camera\n";
        return false;
    }
    return true;
}

void captureAndDisplay(cv::VideoCapture &cap) {
    cv::Mat frame;
    cv::Mat grayFrame;
    std::cout << "Start grabbing" << std::endl
              << "Press any key to terminate" << std::endl;

    while (true) {
        // Wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // Check if we succeeded
        if (frame.empty()) {
            std::cerr << "ERROR! Blank frame grabbed\n";
            break;
        }

        // Convert the image to grayscale
        cvtColor(frame, grayFrame, cv::COLOR_BGR2GRAY);

        // Apply salt and pepper noise
        AddSaltAndPepperNoise(grayFrame, 0.1, 0.1);

        // Show live and wait for a key with timeout long enough to show images
        imshow("Live", grayFrame);
        if (cv::waitKey(5) >= 0) {
            break;
        }
    }
}

int main()
{
    cv::VideoCapture cap;
    if (!initializeCamera(cap))
    {
        return -1;
    }

    captureAndDisplay(cap);
    return 0;
}