#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <memory>
#include "image.hpp"
#include "image_binarizer.hpp"
#include "image_segmenter.hpp"
#include "letter_recognizer.hpp"

template <class ColorType>
class ImageProcessor
{
protected:
    using BinarizerType = std::unique_ptr<ImageBinarizer<ColorType>>;
    using SegmenterType = std::unique_ptr<ImageBinarizer<ColorType>>;
    using RecognizerType = std::unique_ptr<ImageBinarizer<ColorType>>;

    using ImageType = Image<ColorType>;

public:

    ImageProcessor(BinarizerType binarizer, SegmenterType segmenter, RecognizerType recognizer);
    std::string process(const ImageType& image);

private:
    BinarizerType binarizer;
    SegmenterType segmenter;
    RecognizerType recognizer;
};

#endif
