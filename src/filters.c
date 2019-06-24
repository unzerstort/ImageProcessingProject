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

Image blurring(Image img)
{
	int i, j, k, l;
	float blur[3][3] = {{0.111111111,0.111111111,0.111111111},
                        {0.111111111,0.111111111,0.111111111},
                        {0.111111111,0.111111111,0.111111111}};

	for (i = 1; i < img.height - 1; i++)
	{
		for (j = 1; j < img.width; j++)
		{
			int red = 0, green = 0, blue = 0;

			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					red += (img.pixels[i - 1 + k][j - 1 + l].red) * blur[k][l];
					green += (img.pixels[i - 1 + k][j - 1 + l].green) * blur[k][l];				
					blue += (img.pixels[i - 1 + k][j - 1 + l].blue) * blur[k][l];		
				}
			}
  			
			if (red > 255)
			{
				red = 255;
			}
			if (red < 0)
			{
				red = 0;
			}
			if (green > 255)
			{
				green = 255;
			}
			if (green < 0)
			{
				green = 0;
			}
			if (blue > 255)
			{
				blue = 255;
			}
			if (blue < 0)
			{
				blue = 0;
			}
  			
			img.pixels[i][j].red = red;
			img.pixels[i][j].green = green;
			img.pixels[i][j].blue = blue;
		}
	}

	return img;
}

Image sharpening(Image img)
{
	int i, j, k, l;
	float sharp[3][3] = {{0,-1,0},
                        {-1,5,-1},
                        {0,-1,0}};

	for (i = 1; i < img.height - 1; i++)
	{
		for (j = 1; j < img.width; j++)
		{
			int red = 0, green = 0, blue = 0;

			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					red += (img.pixels[i - 1 + k][j - 1 + l].red) * sharp[k][l];
					green += (img.pixels[i - 1 + k][j - 1 + l].green) * sharp[k][l];				
					blue += (img.pixels[i - 1 + k][j - 1 + l].blue) * sharp[k][l];		
				}
			}
  			
			if (red > 255)
			{
				red = 255;
			}
			if (red < 0)
			{
				red = 0;
			}
			if (green > 255)
			{
				green = 255;
			}
			if (green < 0)
			{
				green = 0;
			}
			if (blue > 255)
			{
				blue = 255;
			}
			if (blue < 0)
			{
				blue = 0;
			}
  			
			img.pixels[i][j].red = red;
			img.pixels[i][j].green = green;
			img.pixels[i][j].blue = blue;
		}
	}

	return img;

}

Image edgeDetection(Image img)
{
	int i, j, k, l;
	float edge[3][3] = {{-1,-1,-1},
	                    {-1,8,-1},
                        {-1,-1,-1}};

	for (i = 1; i < img.height - 1; i++)
	{
		for (j = 1; j < img.width; j++)
		{
			int red = 0, green = 0, blue = 0;

			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					red += (img.pixels[i - 1 + k][j - 1 + l].red) * edge[k][l];
					green += (img.pixels[i - 1 + k][j - 1 + l].green) * edge[k][l];				
					blue += (img.pixels[i - 1 + k][j - 1 + l].blue) * edge[k][l];		
				}
			}
  			
			if (red > 255)
			{
				red = 255;
			}
			if (red < 0)
			{
				red = 0;
			}
			if (green > 255)
			{
				green = 255;
			}
			if (green < 0)
			{
				green = 0;
			}
			if (blue > 255)
			{
				blue = 255;
			}
			if (blue < 0)
			{
				blue = 0;
			}
  			
			img.pixels[i][j].red = red;
			img.pixels[i][j].green = green;
			img.pixels[i][j].blue = blue;
		}
	}

	return img;

}

Image negativeColors(Image img)
{
	int i, j;
	
	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{
			img.pixels[i][j].red = 255 - img.pixels[i][j].red;
			img.pixels[i][j].green = 255 - img.pixels[i][j].green;
			img.pixels[i][j].blue = 255 - img.pixels[i][j].blue;		
		}
	}
	
	printf("Negative colors successfully applied! ;)\n");

	return img;
}
