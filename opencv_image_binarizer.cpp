#include <memory>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "opencv_image_binarizer.hpp"

std::unique_ptr<Image<OpenCVColorType>> OpenCVImageBinarizer::apply(const ImageType& image) const
{
	cv::Mat img(image.height(), image.width(), CV_8UC3);
	for (int i = 0; i < img.rows; ++i)
    {
		for (int j = 0; j < img.cols; ++j)
        {
			img.at<cv::Vec3b>(i, j) = image[{i, j}];
        }
    }
	
	cv::cvtColor(img, img, CV_BGR2GRAY);
    cv::Mat res(img.rows, img.cols, CV_8UC3);
	cv::adaptiveThreshold(
                            img, 
                            res, 
                            settings.maxValue, 
                            cv::ADAPTIVE_THRESH_GAUSSIAN_C, 
                            cv::THRESH_BINARY, 
                            settings.blockSize, 
                            settings.C
                         ); 
    
    cv::cvtColor(res, res, CV_GRAY2RGB);

	return std::make_unique<OpenCVImage>(res);
}
