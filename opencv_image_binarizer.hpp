#ifndef OPENCV_IMAGE_BINARAIZER_HPP
#define OPENCV_IMAGE_BINARAIZER_HPP

#include "image_binarizer.hpp"
#include "opencv_image.hpp"

class OpenCVImageBinarizer: public ImageBinarizer<OpenCVColorType> 
{
protected:    
    using ImageType = Image<OpenCVColorType>;

public:
    std::unique_ptr<ImageType> binarize(const ImageType& image) override;
};

#endif
