#include <memory>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv_image_binarizer.hpp"

std::unique_ptr<Image<OpenCVColorType>> OpenCVImageBinarizer::apply(const ImageType& image) const
{
	cv::Mat img(image.height(), image.width(), CV_8UC3);
	for (int i = 0; i < img.rows; ++i)
		for (int j = 0; j < img.cols; ++j)
			img.at<cv::Vec3b>(i, j) = image[{i, j}];
	
    cv::Mat img2(image.height(), image.width(), CV_8UC3);
	cv::cvtColor(img, img2, CV_BGR2GRAY);
	
    cv::Mat res(img2.rows, img2.cols, CV_8UC3);
	cv::adaptiveThreshold(img2, res, 255, cv::ADAPTIVE_THRESH_GAUSSIAN_C, cv::THRESH_BINARY, 5, 1); // NOTE here are many variable parametrs

    cv::cvtColor(res, res, CV_GRAY2RGB);

	return std::make_unique<OpenCVImage>(res);
}
