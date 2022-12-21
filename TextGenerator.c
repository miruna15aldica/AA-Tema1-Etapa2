#include "TextGenerator.h"

void generateString(char *s, int length, int MAX_LETTERS) {
    for(int i = 0; i < length; i++) {
        s[i] = rand() % MAX_LETTERS + 'A';
    }
    s[length] = '\0';
}
