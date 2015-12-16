#ifndef OPENCV_IMAGE_DENOISER_HPP
#define OPENCV_IMAGE_DENOISER_HPP

#include "command.hpp"
#include "opencv_image.hpp"

class OpenCVImageDenoiser: public Command<OpenCVColorType> 
{

public:
    std::unique_ptr<ImageType> apply(const ImageType& image) const override;
};

#endif
