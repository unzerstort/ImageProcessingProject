#ifndef UTIL_HEADER
#define UTIL_HEADER

/*
we're using unsigned char because its range is [0, 255], which is the exact interval of values the RGB color system can have :)
concerning the unsigned int, we're using it just to avoid the negative numbers, nothing too complex
*/

#define uchar unsigned char
#define unsint unsigned int

#include <stdio.h>
#include <stdlib.h>

/* ________________________________________
 *|                                        |
 *|   here we define the structs we'll	   |
 *|	  be using inside each function, as    |
 *|	  well as the signatures from the      |
 *|	  utilitary minor functions!           |
 *|________________________________________|
*/

typedef struct Pixel
{
	uchar red;
	uchar green;
	uchar blue;
} Pixel;

typedef struct Image
{
	unsint height;
	unsint width;
	uchar maxRGB;
	Pixel **pixels;
} Image;

Image copyImg(Image *newImg);

#endif
