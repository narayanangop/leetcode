#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int shortestDistance(char** wordsDict, int wordsDictSize, char* word1, char* word2) {

    int i1, i2;
    int min = INT_MAX;
    i1 = i2 = -1;
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    for (int i = 0; i < wordsDictSize; i++) {
        if(strncmp(wordsDict[i], word1, len1) == 0) {
            i1 = i;
        } else if(strncmp(wordsDict[i], word2, len2) == 0) {
            i2 = i;
        }

        if((i1 != -1) && (i2 != -1)) {
            int new_min = abs(i1 - i2);
            if(min > new_min) {
                min = new_min;
            }
        }
    }

    return min;
    
}

int main() {
    char wordsDict[5][9] = { // 5 words, maximum length 8 + 1 for the null terminator
        "practice",
        "makes",
        "perfect",
        "coding",
        "makes"
    };

    char *ptr[5];
    // To demonstrate, printing out the array
    for (int i = 0; i < 5; i++) {
        ptr[i] = wordsDict[i];
        printf("%s\n", ptr[i]);
    }

    int ret = shortestDistance(ptr, (sizeof(ptr)/sizeof(ptr[0])),"makes", "coding");
    printf("%d\n", ret);

    return 0;
}