#ifndef OPENCV_IMAGE_DENOISER_HPP
#define OPENCV_IMAGE_DENOISER_HPP

#include "image_denoiser.hpp"
#include "opencv_image.hpp"

class OpenCVImageDenoiser: public ImageDenoiser<OpenCVColorType> 
{
protected:    
    using ImageType = Image<OpenCVColorType>;

public:
    std::unique_ptr<ImageType> denoise(const ImageType& image) const override;
};

#endif
