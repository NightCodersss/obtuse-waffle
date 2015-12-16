#ifndef OPENCV_IMAGE_BINARAIZER_HPP
#define OPENCV_IMAGE_BINARAIZER_HPP

#include "command.hpp"
#include "opencv_image.hpp"

class OpenCVImageBinarizer: public Command<OpenCVColorType> 
{
public:
    std::unique_ptr<ImageType> apply(const ImageType& image) const override;
protected:
    static constexpr struct{
        int maxValue;
        int blockSize;
        int C; 
    } settings = {255, 5, 1};
};

#endif
