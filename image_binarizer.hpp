#ifndef IMAGE_BINARIZER_HPP
#define IMAGE_BINARIZER_HPP

#include <memory>
#include "image.hpp"

template <class ColorType>
class ImageBinarizer
{
protected:    
    using ImageType = Image<ColorType>;

public:
    virtual std::unique_ptr<ImageType> binarize(const ImageType& image) = 0;
};

#endif
