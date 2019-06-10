#include<stdio.h>
#include "../include/util.h"
#include "../include/write.h"

void writePPM(Image *img, char *filename)
{
	// change this into filename/path l8r
	FILE *outImage = fopen("../res/got.ppm", "w");

	//writing the image's header	
	fprintf(outImage, "P3\n");
	fprintf(outImage, "%u %u\n", img->width, img->height);
	fprintf(outImage, "%u\n", img->maxRGB);

	//writing all rgb values 
	int i, j;

	for (i = 0; i < img->height; i++)
	{
		for (j = 0; j < img->width; j++)
		{
			fprintf(outImage, "%i\n%i\n%i\n", img->pixels[i][j].red, img->pixels[i][j].green, img->pixels[i][j].blue);
		}
	}

	fclose(outImage);
}
