#ifndef UTILS_HEADER
#define UTILS_HEADER

#include<stdio.h>
#include<stdlib.h>

#define uchar unsigned char
#define uint unsigned int

typedef struct
{
	uchar red;
	uchar green;
	uchar blue;
} Pixel;

typedef struct
{
	uint height;
	uint width;
	Pixel **pixels;
} Image;

#endif
