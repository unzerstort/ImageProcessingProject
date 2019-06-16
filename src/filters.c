#include "filters.h"

/* _________________________________
 *|                                 |
 *|	   here we'll implement all |
 *|    the filters we use through   |
 *|    the project :)		    |
 *|_________________________________|
*/

// in case you are wondering how does this first one work, here we use themost common formula used in image processors (like Photoshop, GIMP, etc.),that basically adjusts each RGB color to the actual perception of the human eye. nice, huh? 

Image grayscale(Image newImg)
{
	int i, j;
	uint gray;

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

Image threshold(Image img)
{
	int i, j;

	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{
			if (img.pixels[i][j].red > 128)
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
Image imgPixel(Image *img, int x, int y){
	return &(img->pixels[y * img->width + x]);
}
Image rotation(Image img)
{
	printf("Choose the type of rotation:\n");
	printf("1 - Rotation 90 degrees to the right\n");
	//printf("2 - Rotation 90 degrees to the left\n");
	//printf("3 - Rotation 180 degrees\n");

	int pixelX, pixelY, option;

	scanf("%d", &option);

	if(option == 1){
		for(pixelY = 0; pixelY < img->height; pixelY++){
			for(pixelX = 0; pixelX < img->width; pixelX++){
				Pixel *original = imgPixel(img, pixelX, pixelY);
				Pixel *rotation = imgPixel(img, img->height - pixelY - 1, pixelX);
				rotation->r = original->r;
				rotation->g = original->g;
				rotation->b = original->b;
			}
		}
	}
	
	printf("Rotation successfully applied! :) \n");

	return img
}	
