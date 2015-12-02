#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <memory.h>
#include "image.hpp" 

class ImageType;

template <class ColorType>
class Command
{    
protected:
    using ImageType = Image<ColorType>;
public:
    virtual unique_ptr<ImageType> apply(const ImageType &image) const = 0;
};


#endif
