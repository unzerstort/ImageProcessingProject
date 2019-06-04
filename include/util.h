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
	uint maxRGB;
	Pixel **pixels;
} Image;

void printMenu();

#endif
