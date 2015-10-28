#ifndef OPENCV_IMAGE_LOADER_HPP
#define OPENCV_IMAGE_LOADER_HPP

#include "image_loader.hpp"
#include "opencv_image.hpp"

class OpenCVImageLoader : public ImageLoader<OpenCVColorType>
{
public:    
    OpenCVImageLoader() = default;
	std::unique_ptr<ImageType> load(const std::string& path) const override;
};

#endif
