#include "menu.h"

void printMenu()
{
	// printing the starting menu with the available options

    printf("     ---------------------------------------------------------------------\n");
    printf("    |  _     _  _______  ___      _______  _______  __   __  _______  __  |\n");
    printf("    | | |   | ||       ||  |     |   ____||  ___  ||  |_|  ||       ||  | |\n");
    printf("    | | | _ | ||    ___||  |     |  |     | |   | ||       ||    ___||  | |\n");
    printf("    | | || || ||   |___ |  |     |  |     | |   | || |   | ||   |___ |  | |\n");
    printf("    | | |   | ||    ___||  |     |  |     | |   | || ||_|| ||    ___||__| |\n");
    printf("    | |   _   ||   |___ |  |____ |  |____ | |___| || |   | ||   |___  __  |\n");
    printf("    | |__| |__||_______||_______||_______||_______||_|   |_||_______||__| |\n");
    printf("    |                                                                     |\n");
    printf("    | Image Processing Program                                            |\n");
    printf("    | \tdeveloped by: Lucas Emanoell & Sandra Bastos.                     |\n");
    printf("    |                                                                     |\n");
    printf("     ---------------------------------------------------------------------\n");
    printf("\n");
    printf("\tChoose the options you want by turn:\n");
    printf("\t1. Gray scale\n");
    printf("\t2. Thresholding\n");
    printf("\t3. Blurring\n");
    printf("\t4. Sharpening\n");
    printf("\t5. Edge Detection\n");
    printf("\t6. Rotate\n");
    printf("\t7. Zoom\n");
    printf("\t8. EXTRA 1\n");
    printf("\t9. EXTRA 2\n");
    printf("\t0. Exit\n");
}

/* using typedef enum to define the number order of options
 * (for instance, EXIT = 0, READDPPM = 1 and so on)
 */

typedef enum Options
{
	EXIT,
	GRAYSCALE,
	THRESHOLDING,
	BLURRING,
	SHARPENING,
	EDGEDETECTION,
	ROTATE,
	ZOOM,
	NEGATIVE,
	EMBOSSING
} Options;

/* this guy here will receive the user's entered number and 
 * will judge whether the choice is valid or not according 
 * to the typedef enum above
 */

void menuOptions()
{
	int aux = 1, op;
	Options option;
    scanf("%d", &option);

	char *filepath;
	Image image;
	

		switch(option)
		{
			case EXIT:
				aux = 0;
				printf("Exiting the program...\n");
				break;
					
			case GRAYSCALE:
				//grayscale function
				image = readPPM(filepath);
				image = grayscale(image);
				writePPM(filepath, image);
				break;

			case THRESHOLDING:
				//thresholding function
				image = readPPM(filepath);
				image = thresholding(image);
				writePPM(filepath, image);
				break; 
	
			case BLURRING:
				//blurring function
				image = readPPM(filepath);
				image = blurring(image);
				writePPM(filepath, image);
				break;

			case SHARPENING:
				//sharpening function
				image = readPPM(filepath);
				image = sharpening(image);
				writePPM(filepath, image);
				break;	

			case EDGEDETECTION:
				//edge detection function
				image = readPPM(filepath);
				image = edgeDetection(image);
				writePPM(filepath, image);
				break;	

			case ROTATE:
				// rotate function
				image = readPPM(filepath);
				printf("\tChoose one option:\n");
				printf("\t1 - Rotation 90 degrees left\n");
				printf("\t2 - Rotation 90 degrees right\n");
				printf("\t3 - Rotation 180 degrees\n");
				scanf("%d",&op);

				if (op == 1)
				{
					image = rotate90DegreesLeft(image);
				}
				else if (op == 2)
				{
					image = rotate90DegreesRight(image);
				}
				else
				{
					image = rotate90DegreesLeft(image);
					image = rotate90DegreesLeft(image);
				}
				writePPM(filepath, image);
				break;
				
			case ZOOM:
				//zoom out function
				image = readPPM(filepath);

				printf("\tChoose one option:\n");
				printf("\t1 - Enlarge\n");
				printf("\t2 - Reduce\n");
				scanf("%d",&op);
			
				if (op == 1)
				{
					image = enlarge(image);
				}
				else
				{
					image = reduce(image);
				}
				
				writePPM(filepath, image);
				break;

			case NEGATIVE:
				// extra1 function (probably complementary colors)
				image = readPPM(filepath);
				image = negativeColors(image);
				writePPM(filepath, image);
				break;

			case EMBOSSING:
				image = readPPM(filepath);
				image = embossing(image);
				writePPM(filepath, image);				
				break;
				
			default:
				printf("\tInvalid option, try again.\n");
		}
			
		if (aux == 1)
			menuOptions();
}
