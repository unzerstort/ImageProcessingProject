#ifndef TRANSFORM_HEADER
#define TRANSFORM_HEADER

/* ___________________________
 *|                           |
 *|  this library has all the |
 *|  signatures of the        |
 *|  functions related to     |
 *|  rotation and zoom!       |
 *|___________________________|
*/
  

#include "util.h"

Image rotate90DegreesRight(Image);
Image rotate90DegreesLeft(Image);
Image rotate180Degrees(Image);
Image horizontalReflection(Image);
Image verticalReflection(Image);
Image reduce(Image);
Image enlarge(Image);
Image overlay(Image);

#endif
