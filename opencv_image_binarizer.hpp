#ifndef OPENCV_IMAGE_BINARAIZER_HPP
#define OPENCV_IMAGE_BINARAIZER_HPP

#include "command.hpp"
#include "opencv_image.hpp"

class OpenCVImageBinarizer: public Command<OpenCVColorType> 
{
//protected:    
//    using ImageType = Image<OpenCVColorType>;
public:
    std::unique_ptr<ImageType> apply(const ImageType& image) const override;
};

#endif
