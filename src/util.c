#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/read.h"
#include "../include/util.h"

Image copyImg(Image *originalImg)
{
	int i, j;
	Image newImg;

	newImg.width = originalImg.width;
	newImg.height = originalImg.height;
	newImg.maxRGB = originalImg.maxRGB;

	newImg.pixels = (Pixel**) calloc(newImg.height, sizeof(Pixel*));

	for (i = 0; i < originalImg.height; i++)
	{
		newImg.pixels = (Pixel*) calloc(newImg.width, sizeof(Pixel));

		for (j = 0; j < originalImg.width; j++)
		{
			newImg.pixels[i][j] = originalImg.pixels[i][j];
		}
	}

	return newImg;

}
