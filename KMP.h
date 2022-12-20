#ifndef KMP_H_
#define KMP_H_

#include <stdio.h>
#include <string.h>

void LPSArray(char* pat, int M, int* lps);
void KMPSearch(char* pat, char* txt);

#endif // KMP_H_
