#ifndef UTIL_HEADER
#define UTIL_HEADER

// we're using unsigned variables just because we won't use their negative values :p

#define uchar unsigned char
#define usint unsigned int

// here we define the structs we'll be using inside each function, as well as the utilitary minor functions!

typedef struct Pixel
{
	uchar red;
	uchar green;
	uchar blue;
} Pixel;

typedef struct Image
{
	usint height;
	usint width;
	usint maxRGB;
	Pixel **pixels;
} Image;

Image copyImg(Image *newImg);

#endif
