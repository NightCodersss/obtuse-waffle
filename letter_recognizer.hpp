#ifndef LETTER_RECOGNIZER_HPP
#define LETTER_RECOGNIZER_HPP

#include <string>
#include "image.hpp"

template <class ColorType>
class LetterRecognizer
{
protected:
    using ImageType = Image<ColorType>

public:
    virtual std::string recognize(const ImageType& image) const = 0;
};

#endif
