#ifndef IMAGE_HPP
#define IMAGE_HPP

template <class ColorType>
class Image
{
public:
	virtual ColorType operator[](int i, int j) const;			
	virtual int width() const;
	virtual int height() const;
};

#endif
