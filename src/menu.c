#include <stdio.h>
#include "../include/read.h"
#include "../include/menu.h"


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
    printf("\t1. Read PPM\n");
    printf("\t2. Thresholding\n");
    printf("\t3. Grey Scale\n");
    printf("\t4. Blurring\n");
    printf("\t5. Sharpening\n");
    printf("\t6. Rotate\n");
    printf("\t7. Zoom in\n");
    printf("\t8. Zoom out\n");
    printf("\t9. EXTRA 1\n");
    printf("\t10. EXTRA 2\n");
    printf("\t0. Exit\n");
}

	// using typedef enum to define the number order of options (for instance, exit = 0, rPPM = 1 and so on)
typedef enum Options
{
	exit,
	rdPPM,
	thr,
	grscl,
	blu,
	sha,
	rot,
	amp,
	red,
	ex1,
	ex2
} Options;

void menuOptions()
{
	// this auxiliar is used to decide when the program will call menuOptions again

	int aux = 1;
	Options option;
    scanf("%d", &option);

	// this switch case will receive the numbers entered by the user and judge them according to the enum type Options 
   	switch(option)
	{
		case exit:
			{
			printf("Exiting the program...\n");
			aux = 0;
			break;
			}
		
		case rdPPM:
			{
			char *filepath;
			Image image;
			image = readPPM(filepath);
			}

		case thr:
			{
			//thresholding function
			//thresholding();
			break; 
			}

		case grscl:
			{
			//grayscale function)
			//Image image;
			//image = grayscale(image);
			break;
			}
			
		case blu:
			{
			//blurring function
			//blurring();
			break;
			}

		case sha:
			{
			//sharpening fucntion
			//sharpening();
			break;
			}

		case rot:
			{
			//rotation function
			//rotation();
			break;
			}

		case amp:
			{
			//zoom out function
			//zoomOut();
			break;
			}

		case red:
			{
			//zoom in fucntion
			//zoomIn();
			break;
			}

		case ex1:
			{
			// extra1 function (probably complementary colors)
			// invertColor();	
			break;
			}

		case ex2:
			{
			//extra2 function (probably image inverter)
			//invertImage();
			break;
			}

		default :
			{
			printf("Invalid option.\n");
			}
		}

		//Recursiveness when the auxiliar has no change.		
		if(aux == 1)
		{
			menuOptions();
		}
}
