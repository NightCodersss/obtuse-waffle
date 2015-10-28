#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <memory>
#include "image_binarizer.hpp"
#include "image_segmenter.hpp"
#include "letter_recognizer.hpp"

class ImageProcessor
{
public:

    ImageProcessor(std::unique_ptr<ImageBinarizer> binarizer
                 , std::unique_ptr<ImageSegmenter> segmenter
                 , std::unique_ptr<LetterRecognizer> recognizer);

    std::string process(
    
private:
    std::unique_ptr<ImageBinarizer> binarizer;
    std::unique_ptr<ImageSegmenter> segmenter;
    std::unique_ptr<LetterRecognizer> recognizer;
};

#endif
