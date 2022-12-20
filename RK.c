#include "RK.h"
 
void search(char pat[], char txt[], int q)
{
    int j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;
 
    // The value of h would be "pow(d, M-1)%q"
    for (int i = 0; i < strlen(pat) - 1; i++)
        h = (256 * h) % q;
        // 256 este numarul de litere din alfabet considerat de noi la inceput
        // luam valoarea maxima
        // valoarea lui h este d^(strlen(pat) -1)mod q
        // iar in exemplul nostru am considerat d = 256
 
    // calculul valorii de hash a functiei pt pattern si pt text
    int i = 0;
    while(i < strlen(pat)) {
        p = (256 * p + pat[i]) % q;
        t = (256 * t + txt[i]) % q;
        i++;
    }
    i = 0;
    while(i <= strlen(txt) - strlen(pat)) {
        if(p == t) {
            // daca valorile functiilor hash sunt egale, putem incepe
            // compararea caracterelor unul carte unul
            int j = 0;
            while(j < strlen(pat)) {
                if(pat[j] != txt[i + j]) {
                    break;
                    // daca am gasit o inegalitatea intre secventa de text si pattern
                    // ne oprim
                }
                j++;
            }
            if (j == strlen(pat)) {
                printf("Pattern found at index %d \n", i);
                // daca j atinge lungimea patternului, s-a comparat
                // intregul pattern si s-a gasit egalitate, deci am
                // gasit o potrivire
            }
        }

            if (i < strlen(txt) - strlen(pat)) {
            t = (256 * (t - h * txt[i]) + txt[strlen(pat) + i]) % q;
            // se poate obtine un modul negativ, dar il 
            // convertim pentru a fi pozitiv
            if (t < 0)
                t = (t + q);
          

        }
        i++;
    }
}
 
// int main()
// {
//     char txt[] = "ABABDABACDABABCABAB";
//     char pat[] = "AB";
 
//     // A prime number
//     int q = 101;
 
//     // function call
//     search(pat, txt, q);
//     return 0;
// }

