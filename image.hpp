#ifndef IMAGE_HPP
#define IMAGE_HPP

template <class ColorType>
class Image
{
	virtual ColorType operator[](int i, int j);			
	virtual int width() const;
	virtual int height() const;
};

#endif
