#ifndef IMAGE_LOADER_HPP
#define IMAGE_LOADER_HPP

#include <string>

template<class ColorType>
class ImageLoader
{
	virtual Image<ColorType> load(std::string path);
};
#endif
