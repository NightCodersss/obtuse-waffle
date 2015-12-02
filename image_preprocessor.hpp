#ifndef IMAGE_PROCESSOR_HPP
#define IMAGE_PROCESSOR_HPP

#include <memory>
#include <vector>
#include "image.hpp"
#include "command.hpp"
#include <functional>

template <class ColorType>
class ImagePreprocessor
{
private:
    using ImageType = Image<ColorType>;
    using CommandType = std::reference_wrapper<const Command<ColorType>>;

public:
    std::unique_ptr<ImageType> preprocess(const ImageType& image, const std::vector<CommandType>& commands) const
    {
        auto ptr = std::unique_ptr<ImageType>{ };
        auto ref = std::cref(image);
        for (const auto& c : commands) 
        {
            ptr = c.get().apply(ref);
            ref = std::cref(*ptr);
        }

        return std::move(ptr);
    }
};
#endif

