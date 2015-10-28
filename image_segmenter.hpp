#ifndef IMAGE_SEGMENTER_HPP
#define IMAGE_SEGMENTER_HPP

#include <memory>
#include <vector>

#include "image.hpp"

template <class ColorType>
class ImageSegmenter
{
protected:
    using ImageType = Image<ColorType>;
public:
    std::vector<std::unique_ptr<ImageType>> segment(const ImageType &image) const;   
};

#endif
