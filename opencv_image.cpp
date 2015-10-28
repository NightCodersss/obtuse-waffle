#include "opencv_image.hpp"

OpenCVImage::OpenCVImage(cv::Mat const& m): image(m) { }

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

void OpenCVImage::show()
{
    cv::namedWindow("", cv::WINDOW_AUTOSIZE);
    cv::imshow("", image);
    cv::waitKey(0);
}
