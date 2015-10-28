#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <utility>

template <class ColorType>
class Image
{
public:
	virtual ColorType operator[](std::pair<int, int> index) const;			
	virtual int width() const;
	virtual int height() const;
};

#endif
