#include "opencv_image_loader.hpp"
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdexcept>

std::unique_ptr<OpenCVImageLoader::ImageType> OpenCVImageLoader::load(const std::string& path) const
{
    cv::Mat image = cv::imread(path.c_str(), CV_LOAD_IMAGE_COLOR); 
    if (!image.data)
    {
        throw std::logic_error("Couldn't load image file from '" + path + "'");
    }

    return std::make_unique<OpenCVImage>(image);
}
