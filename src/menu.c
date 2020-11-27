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
    printf("\tChoose an option below:\n");
    printf("\t1. Gray scale\n");
    printf("\t2. Thresholding\n");
    printf("\t3. Blurring\n");
    printf("\t4. Sharpening\n");
    printf("\t5. Edge Detection\n");
    printf("\t6. Rotate\n");
    printf("\t7. Zoom\n");
    printf("\t8. Extra filters\n");
    printf("\t0. Exit\n");
	printf("\n");
}

/* using typedef enum to define the number order of options
 * (for instance, EXIT = 0, READDPPM = 1 and so on)
 */

enum Options
{
	EXIT,
	GRAYSCALE,
	THRESHOLDING,
	BLURRING,
	SHARPENING,
	EDGEDETECTION,
	ROTATE,
	ZOOM,
	EXTRAS
};

/* this guy here will receive the user's entered number and 
 * will judge whether the choice is valid or not according 
 * to the typedef enum above
 */

void menuOptions()
{
	int aux = 1, q, choice, intensity;
	int option;

	char *filepath;
	Image image  = readPPM(filepath);

	while(aux != 0){
		printMenu();
		scanf("%d", &option);
		switch(option)
		{
			case EXIT:
				aux = 0;
				printf("\tExiting program...\n\n");
				break;
					
			case GRAYSCALE:
				//grayscale function
				image = grayscale(image);
				break;

			case THRESHOLDING:
				//thresholding function
				image = thresholding(image);
				break; 
	
			case BLURRING:
				//blurring function
				printf("\tChoose the blur intensity:\n");
				scanf("%d", &q);
				image = applyBlur(image, q);
				break;

			case SHARPENING:
				//sharpening function
				image = sharpening(image);
				break;	

			case EDGEDETECTION:
				//edge detection function
				image = edgeDetection(image);
				break;	

			case ROTATE:
				// rotate function
				printf("\tChoose one option:\n");
				printf("\t1. Rotate 90 degrees left\n");
				printf("\t2. Rotate 90 degrees right\n");
				printf("\t3. Rotate 180 degrees\n");
				printf("\t4. Horizontal reflection\n");
				printf("\t5. Vertical reflection\n");

				scanf("%d",&choice);

				if (choice == 1)
				{
					image = rotate90DegreesLeft(image);
				}
				else if (choice == 2)
				{
					image = rotate90DegreesRight(image);
				}
				else if (choice == 3)
				{
					image = rotate180Degrees(image);
				}
				else if (choice == 4)
				{
					image = horizontalReflection(image);
				}
				else
				{
					image = verticalReflection(image);
				}
				break;
				
			case ZOOM:
				//zoom out function

				printf("\tChoose one option:\n");
				printf("\t1. Enlarge\n");
				printf("\t2. Reduce\n");
				scanf("%d",&choice);
			
				if (choice == 1)
				{
					image = enlarge(image);
				}
				else if (choice == 2)
				{
					image = reduce(image);
				}
				else
				{
					printf("Invalid option.\n");
				}
				
				break;

			case EXTRAS:
				printf("\tThis is the extra filters' menu!\n");
				printf("\tChoose any of the options below\n\n");
				printf("\t1. Negative colors\n");
				printf("\t2. Embossing\n");
				printf("\t3. Blacklight\n");
				printf("\t4. Overlay \n");
				
				scanf("%d", &choice);
				
				if (choice == 1)
				{
					image = negativeColors(image);
				}
				else if (choice == 2)
				{
					image = embossing(image);
				}
				else if (choice == 3)
				{
					printf("\tNow, enter a number between 1 and 7 in order to define the filter's brightness: ");
					scanf("%d", &intensity);

					image = blacklight(image, intensity);
				}
				else if (choice == 4)
				{
					image = overlay(image);
				}
			
				break;
				
			default:
				printf("\tInvalid option, try again.\n");
		}
	}
	writePPM(filepath, image);
}
