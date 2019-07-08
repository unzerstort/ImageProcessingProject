#ifndef UTIL_HEADER
#define UTIL_HEADER

/*
 * we're using unsigned char because its range is [0, 255], which is 
 * the exact interval of values the RGB color system can have :)
 * concerning the unsigned integer, we're using it just to avoid
 * negative numbers, nothing too complex
*/

#define uchar unsigned char
#define unsint unsigned int

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ________________________________________
 *|                                        |
 *|   here we define the structs we'll     |
 *|   be using inside each function, as    |
 *|   well as the signatures from the      |
 *|   utilitary minor functions!           |
 *|________________________________________|
*/

/* this struct will help us with the manipulation
 * of RGB values in a more understandable way
 */
typedef struct Pixel
{
	uchar red;
	uchar green;
	uchar blue;
} Pixel;

/* the Image struct contains all data we'll obtain
 * when reading the image file and will manipulate
 * later
 */
typedef struct Image
{
	unsint height;
	unsint width;
	uchar maxRGB;
	Pixel **pixels;
} Image;

/* these are the auxiliary functions' signatures.
 * for further informations about them, see read.c
 */
Pixel **allocatePixels(unsint, unsint);
void freeImage(Image *);
Image applyBlur(Image, int);

#endif
