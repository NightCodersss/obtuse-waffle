#ifndef IMAGE_HPP
#define IMAGE_HPP

template <class ColorType>
class Image
{
	Image(int w = 0, int h = 0);
	virtual ColorType operator[](int i, int j);			
	int width();
	int height();
};

#endif
