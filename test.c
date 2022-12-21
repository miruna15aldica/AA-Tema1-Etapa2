#include <stdio.h>
#include <time.h>

#include "TextGenerator.h"
#include "KMP.h"
#include "RK.h"

void createTest_01() {
    FILE *fin = fopen("in/Test01.in", "w");
    FILE *fref = fopen("ref/Test01.ref", "w");
    char *pattern = malloc(sizeof(char) * 1000005);
    char *text = malloc(sizeof(char) * 1000005);
    generateString(pattern, 1, 5);
    generateString(text, 1000000, 5);
    fprintf(fin, "%s\n%s\n", pattern, text);
    // TODO - output REF
    fclose(fin);
    fclose(fref);
    free(pattern);
    free(text);
}

void createTests() {
    createTest_01();

}

typedef struct {
    float kmp_time;
    float rk_time;
} benchmark_t;

benchmark_t runTest(char *nr_test) {
    benchmark_t result;
    float startTime;
    float endTime;
    char finName[80];
    char foutKMPName[80];
    char foutRKName[80];
    sprintf(finName, "in/Test%s.in", nr_test);
    sprintf(foutKMPName, "out_KMP/Test%s.out", nr_test);
    sprintf(foutRKName, "out_RK/Test%s.out", nr_test);
    FILE *fin = fopen(finName, "r");
    FILE *foutKMP = fopen(foutKMPName, "w");
    FILE *foutRK = fopen(foutRKName, "w");
    char *pattern = malloc(sizeof(char) * 1000005);
    char *text = malloc(sizeof(char) * 1000005);
    fscanf(fin, "%s", pattern);
    fscanf(fin, "%s", text);

    // running KMP
    startTime = (float) clock() / CLOCKS_PER_SEC;
    strmatch_t kmp_result = KMPSearch(pattern, text);
    endTime = (float) clock() / CLOCKS_PER_SEC;
    result.kmp_time = endTime - startTime;
    fprintf(foutKMP, "%d\n", kmp_result.nr_ap);
    for(int i = 0; i < kmp_result.nr_ap; i++) {
        fprintf(foutKMP, "%d ", kmp_result.v[i]);
    }
    fclose(fin);
    fclose(foutKMP);
    fclose(foutRK);
    free(pattern);
    free(text);
    free(kmp_result.v);
    return result;
}

void verifyTest(char *nr_test) {
    printf("a intrat\n");
    char frefName[80];
    char foutKMPName[80];
    char foutRKName[80];
    sprintf(frefName, "ref/Test%s.ref", nr_test);
    sprintf(foutKMPName, "out_KMP/Test%s.out", nr_test);
    sprintf(foutRKName, "out_RK/Test%s.out", nr_test);
    FILE *fref = fopen(frefName, "r");
    FILE *foutKMP = fopen(foutKMPName, "r");
    //FILE *foutRK = fopen(foutRKName, "r");
    int refN;
    fscanf(fref, "%d", &refN);
    //printf("%d\n", refN);
    int *refV = malloc(sizeof(int) * refN);
    for(int i = 0; i < refN; i++) {
       fscanf(fref, "%d", &refV[i]); 
    }

    int kmpN;
    fscanf(foutKMP, "%d", &kmpN);
    printf("%d\n", kmpN);
    int *kmpV = malloc(sizeof(int) * kmpN);
    for(int i = 0; i < kmpN; i++) {
       fscanf(foutKMP, "%d", &kmpV[i]); 
    }

    // int rkN;
    // fscanf(foutRK, "%d", &rkN);
    // int *rkV = malloc(sizeof(int) * rkN);
    // for(int i = 0; i < rkN; i++) {
    //    fscanf(foutRK, "%d", &rkV[i]); 
    // }

    // if(refN != rkN) {
    //     printf("Error RK - test %s failed\n", nr_test);
    //     goto end_execution;
    // }

    // for(int i = 0; i < refN; i++) {
    //     if(refV[i] != rkV[i]) {
    //         printf("Error RK - test %s failed\n", nr_test);
    //         goto end_execution;
    //     }
    // }

    if(refN != kmpN) {
        printf("Error KMP - test %s failed\n", nr_test);
        goto end_execution;
    }

    for(int i = 0; i < refN; i++) {
        if(refV[i] != kmpV[i]) {
            printf("Error KMP - test %s failed\n", nr_test);
            goto end_execution;
        }
    }

end_execution:
    free(refV);
    free(kmpV);
    //free(rkV);
    fclose(fref);
    fclose(foutKMP);
}


void runAndVerifyTests() {
    benchmark_t benchmark;
    benchmark = runTest("01");
    printf("Time elapsed(kmp): %f\n", benchmark.kmp_time);
    verifyTest("01");
    //runTest("02");
}


int main() {
    srand(time(NULL));
    createTests();
    runAndVerifyTests();


    return 0;
}