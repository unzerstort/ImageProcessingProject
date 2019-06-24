#include "transform.h"
#include "file.h"

Image rotate90DegreesLeft(Image img)
{	int i, j;
	Image rotated;

	rotated.height = img.width;
	rotated.width = img.height;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = (Pixel**) calloc(rotated.height, sizeof(Pixel*));
	
	for(i = 0; i < rotated.height; i++)
	{
		rotated.pixels[i] = (Pixel*) calloc(rotated.width, sizeof(Pixel));
	}

	for (i = 0; i < img.width; i++)
	{
		for (j = 0; j < img.height; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[j][img.width - i - 1].red;
			rotated.pixels[i][j].green = img.pixels[j][img.width - i - 1].green;
			rotated.pixels[i][j].blue = img.pixels[j][img.width - i - 1].blue;
		}

	}

	return rotated;
}

Image rotate90DegreesRight(Image img)
{	int i, j;
	Image rotated;

	rotated.height = img.width;
	rotated.width = img.height;
	rotated.maxRGB = img.maxRGB;

	rotated.pixels = (Pixel**) calloc(rotated.height, sizeof(Pixel*));
	
	for(i = 0; i < rotated.height; i++)
	{
		rotated.pixels[i] = (Pixel*) calloc(rotated.width, sizeof(Pixel));
	}

	for (i = 0; i < img.width; i++)
	{
		for (j = 0; j < img.height; j++)
		{	
			rotated.pixels[i][j].red = img.pixels[img.height - j - 1][i].red;
			rotated.pixels[i][j].green = img.pixels[img.height - j - 1][i].green;
			rotated.pixels[i][j].blue = img.pixels[img.height - j - 1][i].blue;
		}

	}

	return rotated;
}

Image enlarge(Image img)
{
	int i, j;
	Image enlarged;
	
	enlarged.height = img.height * 2;
	enlarged.width = img.width * 2;
	enlarged.maxRGB = img.maxRGB;
		
	enlarged.pixels = (Pixel**) calloc(enlarged.height,  sizeof(Pixel*));

	for (i = 0; i < enlarged.height; i++)
	{
		enlarged.pixels[i] = (Pixel*) calloc(enlarged.width, sizeof(Pixel));
	}	
		
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
	
	return enlarged;
}

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
		printf("Image size: %d x %d\n", reduced.height, reduced.width);
		reduced.pixels = (Pixel**) calloc(reduced.height,  sizeof(Pixel*));

		for (i = 0; i < reduced.height; i++)
		{
			reduced.pixels[i] = (Pixel*) calloc(reduced.width, sizeof(Pixel));
		}

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

	return reduced;	
}
