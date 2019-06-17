#include<stdio.h>
#include<stdlib.h>

#include "file.h"

Image readPPM(char *filepath)
{
	filepath = calloc(100, sizeof(char));

	printf("Insert the path of the PPM file you wish to process: ");
	scanf("%s", filepath);

	FILE *image;
	image = fopen(filepath, "r");

	printf("Reading image file...\n");

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
	else
	{
		printf("The maximum RGB value is: %u.\n", img.maxRGB);
	}

	// pixel mapping
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
