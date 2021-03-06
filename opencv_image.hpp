#ifndef OPENCV_IMAGE_HPP
#define OPENCV_IMAGE_HPP

#include <opencv2/opencv.hpp>

#include "image.hpp"
using OpenCVColorType = cv::Vec3b;

class OpenCVImage: public Image<OpenCVColorType>
{
public: 

	OpenCVImage(cv::Mat const& m);

	OpenCVColorType operator[](std::pair<int, int> index) const override;			
	int width() const override;
	int height() const override;
    void show();
private:
	cv::Mat image;
};

#endif
