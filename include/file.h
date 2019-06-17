#ifndef READ_HEADER
#define READ_HEADER

#include "util.h"

Image readPPM(char *filepath);
void writePPM(char *filepath, Image img);

#endif
