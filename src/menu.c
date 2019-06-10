#include <stdio.h>
#include "../include/read.h"
#include "../include/menu.h"

void printMenu()
{
//Printing the menu with the following options.
    printf("     ---------------------------------------------------------------------\n");
    printf("    |  _     _  _______  ___      _______  _______  __   __  _______  __  |\n");
    printf("    | | | _ | ||       ||   |    |     __||       ||  |_|  ||       ||  | |\n");
    printf("    | | || || ||    ___||   |    |    |   |   _   ||       ||    ___||  | |\n");
    printf("    | |       ||   |___ |   |    |    |   |  | |  ||       ||   |___ |  | |\n");
    printf("    | |       ||    ___||   |___ |    |   |  |_|  ||       ||    ___||__| |\n");
    printf("    | |   _   ||   |___ |       ||    |__ |       || ||_|| ||   |___  __  |\n");
    printf("    | |__| |__||_______||_______||_______||_______||_|   |_||_______||__| |\n");
    printf("    |                                                                     |\n");
    printf("    | Image Processing Program                                            |\n");
    printf("    | Program developed by: Lucas Emanoell & Sandra Bastos.               |\n");
    printf("    |                                                                     |\n");
    printf("     ---------------------------------------------------------------------\n");
    printf("\n");
    printf("Choose the options you want by turn:\n");
    printf("1  - Read PPM\n");
    printf("2  - Thresholding\n");
    printf("3  - Grey Scale\n");
    printf("4  - Blurring\n");
    printf("5  - Sharpening\n");
    printf("6  - Rotationing\n");
    printf("7  - Zoom in\n");
    printf("8  - Zoom out\n");
    printf("9  - EXTRA 1\n");
    printf("10 - EXTRA 2\n");
    printf("0  - Exit\n");
}

//Using enum to list the options in order.
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
//Auxiliar used to decide when the program will do the recursion.
	int aux = 1;
	Options option;
    scanf("%d", &option);

//Applying the switch with enumeration.
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
			Image originalImg;
			originalImg = readPPM(filepath);
			}

		case thr:
			{
			//thresholding function
			//thresholding();
			break; 
			}

		case grscl:
			{
			//grey scale function
			//greyScale();
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
			//extra2 function (probably invert image)
			//invertImage();
			break;
			}

		default :
			{
			printf("Invalid term.\n");
			}
		}
//Recursiveness when the auxiliar has no change.		
		if(aux == 1)
		{
			menuOptions();
		}
}
