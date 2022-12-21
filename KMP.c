#include "KMP.h"

// Prints occurrences of txt[] in pat[]
strmatch_t KMPSearch(char* pat, char* txt)
{

    const int lenPat = strlen(pat);
    const int lenTxt = strlen(txt); 

    strmatch_t result;
    result.v = malloc(sizeof(int) * strlen(txt));
    result.nr_ap = 0;
    int i = 0, j = 0;

    int *lps = malloc(sizeof(int) * lenPat);
    // calculul efectiv al vectorului LPS
    LPSArray(pat, lenPat, lps);

    while ((lenPat - i) <= (lenTxt - j)) {
        if (pat[i] == txt[j]) {
            ++i; // se trece mai departe cu comparatia si in pattern
            ++j; // si in text
        }
        
        if (i == lenPat) {
            // cand s-a atins egalitatea intre i si 
            // pattern inseamna ca intreg patternul 
            // a fost gasit in text, deci poate fi afisat
            // deoarece se termina la indexul j si e de
            // lungime i, il vom incepe de la j-i
            result.v[result.nr_ap] = j - i;
            result.nr_ap++;
            //printf("Found pattern at index %d\n", j - i);
            i = lps[i - 1];
        }
 
        // mismatch dupa j potriviri
        if (pat[i] != txt[j] && j < lenTxt) {
            if(i != 0) {
                i = lps[i - 1];
            } else {
                j++;
            }

        }
    }
    free(lps);
    return result;
}
 
// realizam completarea vectorului LPS
void LPSArray(char* pat, int M, int* lps)
{
    // lungimea propper sufix
    int len = 0;
    lps[0] = 0; // primul element e intotdeauna 0, deoarece 
    // comparam un singur caracter intre el
 
    // for-ul calculeaza de la 1 la M - 1
    for(int i = 1; i < M; i++) {
        if (pat[i] == pat[len]) {
            lps[i] = len++;
            i++;
        }
        else
        {
            if (len != 0) {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
 
// int main()
// {
//     char txt[] = "ABABDABACDABABCABAB";
//     char pat[] = "AB";
//     KMPSearch(pat, txt);
//     return 0;
// }
