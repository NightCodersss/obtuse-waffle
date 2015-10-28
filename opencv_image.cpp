#include "opencv_image.hpp"

int OpenCVImage::width() const
{
	return image.cols;
}

int OpenCVImage::height() const
{
	return image.rows;
}

OpenCVColorType OpenCVImage::operator[](std::pair<int, int> index) const
{
	return image.at<cv::Vec3b>(index.first, index.second);
}
