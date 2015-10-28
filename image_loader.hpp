#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

#include <string>
#include <memory>

template<class ColorType>
class ImageLoader
{
protected:
    using ImageType = Image<ColorType>;

public:
	virtual std::unique_ptr<ImageType> load(const std::string& path) const = 0;
};
#endif
