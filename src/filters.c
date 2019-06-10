#include "../include/filters.h"
#include "../include/util.h"

Image *grayscale(Image *newImg)
{
	int i, j;
	uint gray;

	for (i = 0; i < newImg->height; i++)
	{
		for (j = 0; j < newImg->width; j++)
		{
			gray = ((newImg->pixels[i][j].red)*0.3) + ((newImg->pixels[i][j].green)*0.59) + ((newImg->pixels[i][j].blue)*0.11);

			newImg->pixels[i][j].red = gray;
			newImg->pixels[i][j].green = gray;
			newImg->pixels[i][j].blue = gray;
		}
	}

	printf("Grayscale successfully applied! :)\n");

	return newImg;
}
