#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <memory>
#include "image.hpp"
#include "command.hpp"
#include "image_segmenter.hpp"
#include "image_preprocessor.hpp"
#include "letter_recognizer.hpp"

template <class ColorType>
class ImageProcessor
{
protected:
    using ImagePreprocessorType = ImageProcessor<ColorType>;
    using SegmenterType = std::unique_ptr<ImageSegmenter<ColorType>>;
    using RecognizerType = std::unique_ptr<LetterRecognizer<ColorType>>;
    using CommandType = Command<ColorType>;
    using ImageType = Image<ColorType>;


public:

    ImageProcessor(SegmenterType segmenter, RecognizerType recognizer, std::vector<CommandType> commands) 
        : segmenter(segmenter)
        , recognizer(recognizer)
        , commands(commands)
    {
    }

    std::string process(const ImageType& image)
    {
        auto im = preprocessor.preprocess(image, commands);
        auto images = segmenter.segment(*im);

        return "";
    }

private:
    ImagePreprocessorType preprocessor;
    std::vector<std::unique_ptr<Command<ColorType>>> commands;
    SegmenterType segmenter;
    RecognizerType recognizer;
};


#endif
