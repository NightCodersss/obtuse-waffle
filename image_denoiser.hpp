#ifndef IMAGE_DENOISER_HPP
#define IMAGE_DENOISER_HPP

#include <memory>
#include <vector>

#include "image.hpp"

template <class ColorType>
class ImageDenoiser
{
protected:
    using ImageType = Image<ColorType>;
public:
    virtual std::unique_ptr<ImageType> denoise(const ImageType &image) const = 0;
};

#endif
