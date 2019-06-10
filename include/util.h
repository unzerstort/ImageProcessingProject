#ifndef UTIL_HEADER
#define UTIL_HEADER

#define uchar unsigned char
#define uint unsigned int

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

#endif
