#include<stdlib.h>
#include "util.h"

Image *newImage(uint height, uint width, uchar maxRGB)
{
	Image *newImg = (Image *) malloc(sizeof(Image));
	
	newImg->height = height;
	newImg->width = width;
	newImg->maxRGB = maxRGB;

	newImg->pixels = (Pixel *) malloc(height * width * sizeof(Pixel));

	return newImg;
}
