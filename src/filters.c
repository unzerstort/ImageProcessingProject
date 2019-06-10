#include "../include/filters.h"
#include "../include/util.h"

Image *grayscale(Image *newImg)
{
	int i, j;
	uint gray;

	for (i = 0; i < img->height; i++)
	{
		for (j = 0; j < img->width; j++)
		{
			gray = ((img->pixels[i][j].red)*0.3) + ((img->pixels[i][j].green)*0.59) + ((img->pixels[i][j].blue)*0.11);

			img->pixels[i][j].red = gray;
			img->pixels[i][j].green = gray;
			img->pixels[i][j].blue = gray;
		}
	}
}
