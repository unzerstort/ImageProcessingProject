#include "transform.h"
#include "file.h"

Image rotate90DegreesLeft(Image img)
{
	int i, j;
	Image rotated;

	rotated.height = img.width;
	rotated.width = img.height;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = allocatePixels(rotated.height, rotated.width);

	for (i = 0; i < img.width; i++)
	{
		for (j = 0; j < img.height; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[j][img.width - i - 1].red;
			rotated.pixels[i][j].green = img.pixels[j][img.width - i - 1].green;
			rotated.pixels[i][j].blue = img.pixels[j][img.width - i - 1].blue;
		}

	}

	printf("Rotation Reflection applied successfully! :)\n");

	return rotated;
}

Image rotate90DegreesRight(Image img)
{	
	int i, j;
	Image rotated;

	rotated.height = img.width;
	rotated.width = img.height;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = allocatePixels(rotated.height, rotated.width);

	for (i = 0; i < img.width; i++)
	{
		for (j = 0; j < img.height; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[img.height - j - 1][i].red;
			rotated.pixels[i][j].green = img.pixels[img.height - j - 1][i].green;
			rotated.pixels[i][j].blue = img.pixels[img.height - j - 1][i].blue;
		}

	}

	printf("\tRotation Reflection applied successfully! :)\n");

	return rotated;
}

// rotates the image in 180 degrees
Image rotate180Degrees(Image img)
{
	int i, j;
	Image rotated;

	rotated.height = img.height;
	rotated.width = img.width;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = allocatePixels(rotated.height, rotated.width);

	for (i = 0; i < img.width; i++)
	{
		for (j = 0; j < img.height; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[img.height - i - 1][img.width - j - 1].red;
			rotated.pixels[i][j].green = img.pixels[img.height - i - 1][img.width - j - 1].green;
			rotated.pixels[i][j].blue = img.pixels[img.height - i - 1][img.width - j - 1].blue;
		}

	}

	printf("\tRotation Reflection applied successfully! :)\n");

	return rotated;
}

// simulates the effect of a mirror, reflecting the image  horizontally
Image horizontalReflection(Image img)
{
	int i, j;
	Image rotated;

	rotated.height = img.height;
	rotated.width = img.width;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = allocatePixels(rotated.height, rotated.width);

	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[img.width - i - 1][j].red;
			rotated.pixels[i][j].green = img.pixels[img.width - i - 1][j].green;
			rotated.pixels[i][j].blue = img.pixels[img.width - i - 1][j].blue;
		}

	}

	printf("\tHorizontal reflection applied successfully! :)\n");

	return rotated;
}

// same as the last function, but reflecting the image vertically
Image verticalReflection(Image img)
{
	int i, j;
	Image rotated;

	rotated.height = img.height;
	rotated.width = img.width;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = allocatePixels(rotated.height, rotated.width);

	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[i][img.height - j - 1].red;
			rotated.pixels[i][j].green = img.pixels[i][img.height - j - 1].green;
			rotated.pixels[i][j].blue = img.pixels[i][img.height - j - 1].blue;
		}

	}

	printf("\tVertical reflection applied successfully! :)\n");

	return rotated;
}

// augments the image's size twice 
Image enlarge(Image img)
{
	int i, j;
	Image enlarged;
	
	enlarged.height = img.height * 2;
	enlarged.width = img.width * 2;
	enlarged.maxRGB = img.maxRGB;

	enlarged.pixels = allocatePixels(enlarged.height, enlarged.width);
		
		for(i = 0; i < enlarged.height; i++)
		{
			int aux;

			if (i % 2 == 0)
			{
				aux = i/2;
			}
			else
			{
				aux = (i - 1)/2;
			}
			
			for (j = 0; j < enlarged.width; j++)
			
			{
				if (j % 2 == 0)
				{	
					enlarged.pixels[i][j].red = img.pixels[aux][j/2].red;
					enlarged.pixels[i][j].green = img.pixels[aux][j/2].green;
					enlarged.pixels[i][j].blue = img.pixels[aux][j/2].blue;
				}
				else
				{
					enlarged.pixels[i][j].red = img.pixels[aux][(j-1)/2].red;
					enlarged.pixels[i][j].green = img.pixels[aux][(j-1)/2].green;
					enlarged.pixels[i][j].blue = img.pixels[aux][(j-1)/2].blue;
				}
			}
		}
	
	printf("\tEnlarged image successfully! :)\n");

	return enlarged;
}

// reduces the image's size to its half
Image reduce(Image img)
{	
	int i, j;
	Image reduced;

		if (img.height % 2 == 0)
		{
			reduced.height = img.height / 2;	
		}
		else
		{
			reduced.height = (img.height - 1) / 2;	
		}
		if (img.width % 2 == 0)
		{
			reduced.width = img.width / 2;	
		}
		else
		{
			reduced.width = (img.width - 1) / 2;	
		}

		reduced.maxRGB = img.maxRGB;
		
		reduced.pixels = allocatePixels(reduced.height, reduced.width);

		int aux1 = 0, aux2 = 0;

		for (i = 0; i < img.height; i+=2)
		{
			for (j = 0; j < img.width; j+=2)
			{
				reduced.pixels[aux1][aux2].red = ((img.pixels[i][j].red + img.pixels[i+1][j].red + img.pixels[i+1][j+1].red + img.pixels[i][j+1].red)/4);
				reduced.pixels[aux1][aux2].green = ((img.pixels[i][j].green + img.pixels[i+1][j].green + img.pixels[i+1][j+1].green + img.pixels[i][j+1].green)/4);
				reduced.pixels[aux1][aux2].blue = ((img.pixels[i][j].blue + img.pixels[i+1][j].blue + img.pixels[i+1][j+1].blue + img.pixels[i][j+1].blue)/4);
				aux2++;
			}

			aux2 = 0;
			aux1++;
		}

	printf("\tReduced image successfully! :)\n");

	return reduced;	
}

// overlays an image over the other if they have the same dimensions
Image overlay(Image img)
{
	int i, j;
	char *filepath;
	Image layer;
	layer = readPPM(filepath);
	
	for(i = 0; i < img.height; i++)
	{
		for(j = 0; j < img.width; j++)
		{
			if(layer.pixels[i][j].red != 0 && layer.pixels[i][j].green != 0 && layer.pixels[i][j].blue != 0)
			{
				img.pixels[i][j].red = layer.pixels[i][j].red;
				img.pixels[i][j].green = layer.pixels[i][j].green;
				img.pixels[i][j].blue = layer.pixels[i][j].blue;
			}
		}
	}
	
	printf("\tOverlay applied successfully! :)\n");

	return img;
}
