#include<stdio.h>
#include<stdlib.h>
#include "read.h"
#include "../include/menu.h"
#include "../include/write.h"
#include "../include/util.h"

int main()
{
	char *filepath;

	Image originalImg;

	originalImg = readPPM(filepath);

	//printMenu();
	//menuOptions();

	return 0;
}
