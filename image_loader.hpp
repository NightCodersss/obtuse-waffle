#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

#include <string>
#include <memory>

template<class ColorType>
class ImageLoader
{
	virtual std::unique_ptr<Image<ColorType>> load(std::string& path);
};
#endif
