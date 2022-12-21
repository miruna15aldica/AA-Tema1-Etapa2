#ifndef KMP_H_
#define KMP_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "StrMatchStruct.h"

void LPSArray(char* pat, int M, int* lps);
strmatch_t KMPSearch(char* pat, char* txt);

#endif // KMP_H_
