#include<stdio.h>
#include<stdlib.h>
#include"../include/read.h"

Image readPPM(char *filename)
{
	printf("Reading image file...\n");
	
	FILE *image;
	// change to filename l8r
	image = fopen("../res/got.ppm", "r");

	if (image == NULL)
	{
		printf("File doesn't exist!\n");
		exit(1);
	}
	else
	{
		printf("File loaded successfully :)\n");
	}
	
	Image img;
	long numbytes;
	char format[10];

	fgets(format, 10, image);

	// reading first line to check the image format (P3 or not)
	if (format[0] != 'P' || format[1] != '3')
	{
		printf("Wrong image format (it should be 'P3')!\n");
		fclose(image);
	}
	else
	{
		printf("yay! you got the right image format :D\n");
	}

	// getting the image's width and height!
	if	(!fscanf(image, "%u %u\n", &img.width, &img.height))
	{
		fprintf(stderr, "Invalid image dimensions.\n");
		fclose(image);
		exit(1);
	}
	else
	{
		printf("Dimensions (Width x Height): %u x %u pixels.\n", img.width, img.height);
	}
	
	// reading maximum RGB value
	if (fscanf(image, "%u", &img.maxRGB) != 1)
	{
		fprintf(stderr, "Invalid maximum RBG value.\n");
	}

	//create the new image with same width, height and maxRGB

	// check whats going wrong here 
	img.pixels = (Pixel**) calloc(img.height, sizeof(Pixel*));
	
	int loadedPix = 0;
	for (int i = 0; i < img.height; i++)
	{
		img.pixels[i] = (Pixel*) calloc(img.width, sizeof(Pixel));
		for (int j = 0; j < img.width; j++)
		{
			fscanf(image, "%hhu\n%hhu\n%hhu\n", &img.pixels[i][j].red, &img.pixels[i][j].green, &img.pixels[i][j].blue);
			++loadedPix;
			
			//uncomment the next line if you want to see the actual pixels
			//printf("rgb(%hhu, %hhu, %hhu)\n", img.pixels[i][j].red, img.pixels[i][j].green, img.pixels[i][j].blue);
		}
	}

	printf("Loaded pixels: %d\n", loadedPix);

	return img;
}
