#include <stdio.h>
#include <stdlib.h>

#include "util.h"
#include "filters.h"
    
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

// this function allocates the pixel matrix
Pixel **allocatePixels(unsint height, unsint width)
{
	Pixel **pixels = (Pixel **) calloc(height, sizeof(Pixel *));

	for (int i = 0; i < height; i++)
	{
		pixels[i] = (Pixel *) calloc(width, sizeof(Pixel));
	}

	return pixels;
}

// this guy here frees stuff
void freeImage(Image *img)
{
	for (unsint i = 0; i < img->height; i++)
	{
		free(img->pixels[i]);
	}

	free(img->pixels);
	free(img);
}

// this guy intensifies the blur filter according to user's choice
Image applyBlur(Image img, int q)
{

	if(q > 0)
	{
		img = blurring(img);
		img = applyBlur(img, q - 1);
	}
	if(q == 0)
	{
	printf("\tBlurring successfully applied! :)\n");
	}

	return img;
}
