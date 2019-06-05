#ifndef UTIL_HEADER
#define UTIL_HEADER

#define uchar unsigned char
#define uint unsigned int

typedef struct
{
	uchar red;
	uchar green;
	uchar blue;
} Pixel;

typedef struct
{
	char *buffer;
	uint height;
	uint width;
	uchar maxRGB;
	Pixel **pixels;
} Image;

void printMenu();
Image *newImage(uint height, uint width, uchar maxRGB);

#endif
