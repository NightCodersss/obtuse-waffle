#ifndef IMAGE_BINARIZER_HPP
#define IMAGE_BINARIZER_HPP

#include "image.hpp"

class ImageBinarizer
{
public:
    virtual binarize(const Image& image) = 0;
};

#endif
