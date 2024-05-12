# Webcam Image Processing with OpenCV in C++

This repository features a C++ application that utilizes OpenCV to capture video from the webcam, convert it to grayscale, and overlay salt and pepper noise. It demonstrates basic image manipulation techniques in computer vision using the C++ interface of OpenCV.

## Features

- **Webcam Capture:** Utilizes the webcam to capture live video streams.
- **Grayscale Conversion:** Transforms the live color video feed into grayscale, reducing the complexity for processing.
- **Salt and Pepper Noise:** Adds salt and pepper noise to the grayscale images, a typical noise model that affects digital image data.

## Prerequisites

Ensure you have the following installed to run this project:
- C++ Compiler
- OpenCV
- CMake

## Setup and Installation

Clone this repository and set up the environment to run the application:

```bash
git clone https://github.com/HopeSuffers/OpenCV.git
cd OpenCV

# If using CMake
mkdir build
cd build
cmake ..
make
```

_This project is just me playing around with OpenCV and C++_