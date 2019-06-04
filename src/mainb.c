#include<stdio.h>
#include<stdlib.h>
#include"read.h"

int main()
{
	char *filepath; 
	Image originalImg;

	filepath = (char *) calloc(256, sizeof(char));
	originalImg = readPPM(filepath);

	//printMenu();

	return 0;
}
