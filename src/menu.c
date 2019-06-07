#include <stdio.h>
#include "../include/read.h"
#include "menu.h"

void printMenu()
{
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
    printf("     |                                                                     |\n");
    printf("     ---------------------------------------------------------------------\n");
    printf("\n");
    printf("Choose the options you want by turn:\n");
    printf("1 - Read PPM\n");
    printf("2 - Grey Scale\n");
    printf("3 - Blurring\n");
    printf("4 - Sharpening\n");
    printf("5 - Rotationing\n");
    printf("6 - Zoom in/out\n");
    printf("7 - EXTRA 1\n");
    printf("8 - EXTRA 2\n");
    printf("0 - Exit\n");
}

typedef enum Options
{
	exit,
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

void menuOptions(Options option)
{
	int aux = 1;

    scanf("%d", &option);

   	switch(option)
	{
		case thr:
			{
			//thresholding function
			break; 
			}

		case grscl:
			{
			//grey scale function
			break;
			}
			
		case blu:
			{
			//blurring function
			break;
			}

		case sha:
			{
			//sharpening fucntion
			break;
			}

		case rot:
			{
			//rotation function
			break;
			}

		case amp:
			{
			//zoom out function
			break;
			}

		case red:
			{
			//zoom in fucntion
			break;
			}

		case ex1:
			{
			// extra1 function
			break;
			}

		case ex2:
			{
			//extra2 function
			break;
			}

		case exit:
			{
			printf("Exiting the program...\n");
			aux = 0;
   			exit(0);
			}

		default :
			{
			printf("Invalid term.");
			}
		}
   		 		
		if(aux == 1)
		{
			menuOptions();
		}
}
