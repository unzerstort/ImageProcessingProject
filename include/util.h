#ifndef UTIL_HEADER
#define UTIL_HEADER

// we're using unsigned variables just because we won't use their negative values :p

#define uchar unsigned char
#define uint unsigned int

// here we define the structs we'll be using inside each function, as well as the utilitary minor functions!

typedef struct Pixel
{
	uchar red;
	uchar green;
	uchar blue;
} Pixel;

typedef struct Image
{
	uint height;
	uint width;
	uint maxRGB;
	Pixel **pixels;
} Image;

Image copyImg(Image *newImg);

#endif
