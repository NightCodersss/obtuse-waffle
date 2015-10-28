#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <utility>

template <class ColorType>
class Image
{
public:
	virtual ColorType operator[](std::pair<int, int> index) const = 0;			
	virtual int width() const = 0;
	virtual int height() const = 0;
};

#endif
