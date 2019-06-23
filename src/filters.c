#include "filters.h"

/* _________________________________
 *|                                 |
 *|    here we'll implement all     |
 *|    the filters we use through   |
 *|    the project :)               |
 *|_________________________________|
*/

// in case you are wondering how does this first one work, here we use themost common formula used in image processors (like Photoshop, GIMP, etc.),that basically adjusts each RGB color to the actual perception of the human eye. nice, huh? 

Image grayscale(Image newImg)
{
	int i, j;
	unsint gray;

	for (i = 0; i < newImg.height; i++)
	{
		for (j = 0; j < newImg.width; j++)
		{
			gray = ((newImg.pixels[i][j].red)*0.3) + ((newImg.pixels[i][j].green)*0.59) + ((newImg.pixels[i][j].blue)*0.11);

			newImg.pixels[i][j].red = gray;
			newImg.pixels[i][j].green = gray;
			newImg.pixels[i][j].blue = gray;
		}
	}

	printf("Grayscale successfully applied! :)\n");

	return newImg;
}

Image thresholding(Image img)
{
	int i, j;
	uchar threshold = img.maxRGB/2;

	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{
			if (img.pixels[i][j].red > threshold || img.pixels[i][j].blue > threshold || img.pixels[i][j].green > threshold)
			{
				img.pixels[i][j].red = img.maxRGB;	
				img.pixels[i][j].green = img.maxRGB;
				img.pixels[i][j].blue = img.maxRGB;
			}
			else
			{		
				img.pixels[i][j].red = 0;	
				img.pixels[i][j].green = 0;
				img.pixels[i][j].blue = 0;
			}
		}
	}

	printf("Threshold successfully applied! :) \n");

	return img;
}
Image negative(Image img)
{
	int i, j;
	
	for(i = 0; i < img.height; i++ )
	{
		for(j = 0; j < img.width; j++)
		{
			img.pixels[i][j].red = 255 - img.pixels[i][j].red;
			img.pixels[i][j].green = 255 - img.pixels[i][j].green;
			img.pixels[i][j].blue = 255 - img.pixels[i][j].blue;		
		}
	}
	
	printf("Negative successfully applied! ;)\n");

	return img;
}

