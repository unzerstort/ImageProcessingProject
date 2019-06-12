#include<stdio.h>
#include<stdlib.h>

#include "write.h"

void writePPM(char *filepath, Image img)
{
	filepath = calloc(100, sizeof(char));

	printf("Insert the file's destination, as well as its new name in the end.\n For instance: /home/user/ImageProcessing-ITP/newfile.ppm.\n");
	scanf("%s", filepath);

	FILE *outImage;
	outImage = fopen(filepath, "w");

	//writing the image's header	
	fprintf(outImage, "P3\n");
	fprintf(outImage, "%u %u\n", img.width, img.height);
	fprintf(outImage, "%u\n", img.maxRGB);

	//writing all rgb values 
	int i, j;

	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{
			fprintf(outImage, "%i\n%i\n%i\n", img.pixels[i][j].red, img.pixels[i][j].green, img.pixels[i][j].blue);
		}
	}

	fclose(outImage);

	return;
}
