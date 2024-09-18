#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

const std::string asciiChars = "@%#*+=-:. ";

std::string pixelToAscii(int pixelValue) {
    int index = asciiChars.size() - ((pixelValue) * asciiChars.size() / 255);
    return std::string(1, asciiChars[index - 1]);
}

void generateAsciiArt(const cv::Mat& img) {
    for (int y = 0; y < img.rows; y++) {
        for (int x = 0; x < img.cols; x++) {
            int gray = img.at<uchar>(y, x); 
            std::cout << pixelToAscii(gray);
        }
        std::cout << std::endl;
        std::cout << "      ";
    }
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " --image <image_path> [--size <width>]" << std::endl;
        return 1;
    }

    std::string imagePath;
    int newWidth = 80; 


    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--image") {
            if (i + 1 < argc) {
                imagePath = argv[++i];
            } else {
                std::cerr << "Error: Missing value for --image flag" << std::endl;
                return 1;
            }
        } else if (std::string(argv[i]) == "--size") {
            if (i + 1 < argc) {
                newWidth = std::stoi(argv[++i]);
            } else {
                std::cerr << "Error: Missing value for --size flag" << std::endl;
                return 1;
            }
        }
    }

    if (imagePath.empty()) {
        std::cerr << "Error: --image must be specified with a valid value" << std::endl;
        return 1;
    }

    cv::Mat img = cv::imread(imagePath);
    if (img.empty()) {
        std::cerr << "Error loading image" << std::endl;
        return 1;
    }

    cv::Mat gray;
    cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

    int newHeight = static_cast<int>(gray.rows * (newWidth / static_cast<float>(gray.cols)) * 0.55); 
    cv::resize(gray, gray, cv::Size(newWidth, newHeight));

    generateAsciiArt(gray);
    std::cout << std::endl;

    return 0;
}
