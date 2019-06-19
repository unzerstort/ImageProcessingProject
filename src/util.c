#include <stdio.h>
#include <stdlib.h>

#include "util.h"
    
/*  _____________________________________
 * |                                     |
 * |	here we'll be implementing the	 |
 * |	minor functions of the project	 |
 * |									 |
 * | 	by minor functions I mean they   |
 * |	are the ones that'll help in     |
 * |	other functions :D				 |
 * |_____________________________________|
 */

// just in case you are wondering what exactly this function is doing: it copies the matrix of the original image into the one we'll actually manipulate, so that the original one doesn't go through the changes.

Image copyImg(Image *originalImg)
{	
	int i, j;
	Image newImg;

	newImg.width = originalImg->width;
	newImg.height = originalImg->height;
	newImg.maxRGB = originalImg->maxRGB;

	newImg.pixels = (Pixel**) calloc(newImg.height, sizeof(Pixel*));

	for (i = 0; i < originalImg->height; i++)
	{
		newImg.pixels[i] = (Pixel*) calloc(newImg.width, sizeof(Pixel));

		for (j = 0; j < originalImg->width; j++)
		{
			newImg.pixels[i][j] = originalImg->pixels[i][j];
		}
	}

	return newImg;

}

Pixel **allocatePixels(unsint height, unsint width)
{
	Pixel **pixels = (Pixel **) calloc(height, sizeof(Pixel *));

	for (int i = 0; i < height; i++)
	{
		pixels[i] = (Pixel *) calloc(width, sizeof(Pixel));
	}

	return pixels;
}
