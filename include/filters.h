#ifndef FILTERS_H
#define FILTERS_H

#include "util.h"

/* ____________________________
 *|                            |
 *|  here we have the filters  |
 *|  functions' signatures.    |
 *|  for further details, see  |
 *|  filters.c                 |
 *|____________________________|
 */

Image grayscale(Image);
Image thresholding(Image);
Image blurring(Image);
Image sharpening(Image);
Image edgeDetection(Image);
Image embossing(Image);
Image negativeColors(Image);
Image blacklight(Image, int);

#endif
