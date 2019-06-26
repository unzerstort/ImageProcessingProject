#include "filters.h"

/* ______________________________
 *|                              |
 *|  here we'll implement all    |
 *|  the filters we use through  |
 *|  the project :)              |
 *|______________________________|
*/

/* in case you are wondering how does this first one work, here we use the
 * most common formula used in image processors (like Photoshop, GIMP, etc.), 
 * that basically adjusts each RGB color to the actual perception of the human eye.
 * nice, huh?
 */

Image grayscale(Image img)
{
    int i, j;
	unsint gray;

	for (i = 0; i < img.height; i++)
	{
		for (j = 0; j < img.width; j++)
		{
			gray = ((img.pixels[i][j].red)*0.3) + ((img.pixels[i][j].green)*0.59) + ((img.pixels[i][j].blue)*0.11);

			img.pixels[i][j].red = gray;
			img.pixels[i][j].green = gray;
			img.pixels[i][j].blue = gray;
		}
	}

	printf("\tGrayscale successfully applied! :)\n");

	return img;
}

/* the thresholding function converts a grayscaled image
 * to a binary image, verifying if the RGB values of it
 * are bigger or smaller than the threshold's, which is
 * the maximum RGB value divided by 2
 */
Image thresholding(Image img)
{
	int i, j;
	img = grayscale(img);

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

	printf("\tThresholding successfully applied! :) \n");

	return img;
}

Image blurring(Image img)
{
	int i, j, k, l;

	Image blurred;

	blurred.height = img.height;
	blurred.width = img.width;
	blurred.maxRGB = img.maxRGB;

	blurred.pixels = allocatePixels(blurred.height, blurred.width);

	float blur[3][3] = {{0.111111111, 0.111111111, 0.111111111},
                        {0.111111111, 0.111111111, 0.111111111},
                        {0.111111111, 0.111111111, 0.111111111}};

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
  			
			blurred.pixels[i][j].red = red;
			blurred.pixels[i][j].green = green;
			blurred.pixels[i][j].blue = blue;
		}
	}


	printf("\tBlurring successfully applied! :)\n");

	return blurred;
}

Image sharpening(Image img)
{
	int i, j, k, l;
	Image sharped;

	sharped.height = img.height;
	sharped.width = img.width;
	sharped.maxRGB = img.maxRGB;

	sharped.pixels = allocatePixels(sharped.height, sharped.width);
	
	float sharp[3][3] = { {0, -1, 0 },
                          {-1, 5, -1},
                          {0, -1, 0 } };

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
  			
			sharped.pixels[i][j].red = red;
			sharped.pixels[i][j].green = green;
			sharped.pixels[i][j].blue = blue;
		}
	}

	printf("\tSharpening successfully applied! :)\n");

	return sharped;

}

Image edgeDetection(Image img)
{
	int i, j, k, l;
	Image edge;

	img = grayscale(img);

	edge.height = img.height;
	edge.width = img.width;
	edge.maxRGB = img.maxRGB;

	edge.pixels = allocatePixels(edge.height, edge.width);

	float edgeK[3][3] = { { 1, 0, -1},
                          { 0, 0, 0 },
                          { -1, 0, 1} };

	for (i = 1; i < img.height - 1; i++)
	{
		for (j = 1; j < img.width; j++)
		{
			int red = 0, green = 0, blue = 0;

			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					red += (img.pixels[i - 1 + k][j - 1 + l].red) * edgeK[k][l];
					green += (img.pixels[i - 1 + k][j - 1 + l].green) * edgeK[k][l];				
					blue += (img.pixels[i - 1 + k][j - 1 + l].blue) * edgeK[k][l];		
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
  			
			edge.pixels[i][j].red = red;
			edge.pixels[i][j].green = green;
			edge.pixels[i][j].blue = blue;
		}
	}
	
	printf("\tEdge detection successfully applied! :)\n");

	return edge;

}

Image embossing(Image img)
{
	int i, j, k, l;
	Image embossed;

	embossed.height = img.height;
	embossed.width = img.width;
	embossed.maxRGB = img.maxRGB;

	embossed.pixels = allocatePixels(embossed.height, embossed.width);
	
	float emboss[3][3] = { {-2,-1, 0},
                           {-1, 1, 1},
                           { 0, 1, 2} };

	for (i = 1; i < img.height - 1; i++)
	{
		for (j = 1; j < img.width; j++)
		{
			int red = 0, green = 0, blue = 0;

			for (k = 0; k < 3; k++)
			{
				for (l = 0; l < 3; l++)
				{
					red += (img.pixels[i - 1 + k][j - 1 + l].red) * emboss[k][l];
					green += (img.pixels[i - 1 + k][j - 1 + l].green) * emboss[k][l];				
					blue += (img.pixels[i - 1 + k][j - 1 + l].blue) * emboss[k][l];		
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
  			
			embossed.pixels[i][j].red = red;
			embossed.pixels[i][j].green = green;
			embossed.pixels[i][j].blue = blue;
		}
	}

	printf("\tEmbossing filter successfully applied! :)\n");

	return embossed;

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
	
	printf("\tNegative colors successfully applied! ;)\n");

	return img;
}


