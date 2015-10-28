#ifndef IMAGE_BINARIZER_HPP
#define IMAGE_BINARIZER_HPP

#include "image.hpp"

template <class ColorType>
class ImageBinarizer
{
public:
    virtual ImageType binarize(const Image& image) = 0;

protected:    
    using ImageType = std::unique_ptr<Image<ColorType>>;
};

#endif
