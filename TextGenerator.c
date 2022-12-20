#include<string.h>

void generateString(char s[1000005], int length, int MAX_LETTERS) {
    for(int i = 0; i < length; i++) {
        s[i] = rand() % MAX_LETTERS + 'A';
    }


}


int main() {

    srand(time(NULL));
    char l = rand() % 26 + 'A'; // o litera aleatoare

}