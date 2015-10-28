#include <memory>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv_image_binarizer.hpp"

std::unique_ptr<Image<OpenCVColorType>> OpenCVImageBinarizer::binarize(const ImageType& image)
{
	cv::Mat img(image.height(), image.width(), CV_8UC3);
	for (int i = 0; i < img.rows; ++i)
		for (int j = 0; j < img.cols; ++j)
			img.at<cv::Vec3b>(i, j) = image[{i, j}];
	cv::cvtColor(img, img, CV_BGR2GRAY);
	cv::Mat res(img.rows, img.cols, CV_8UC1);
	cv::adaptiveThreshold(img, res, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 5, 1); // NOTE here are many variable parametrs
	return std::make_unique<OpenCVImage>(res);
}
