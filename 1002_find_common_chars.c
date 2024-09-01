#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

char ** commonChars(char ** words, int wordsSize, int* returnSize){

    int **lookup;
    int i,j,k,min_count;


    char **ret = (char **)malloc(sizeof(char *) * 100);
    if (ret == NULL)
        return NULL;
    *returnSize = 0;

    lookup = (int **)malloc(sizeof(int *) * wordsSize);
    if (lookup == NULL)
        return NULL;

    /* Allocate memory for the lookup table */
    for(i = 0; i<wordsSize; i++) {
        lookup[i] = (int *)malloc(sizeof(int) * 26);
        if (lookup[i] == NULL) {
            return NULL;
        }
        memset(lookup[i], 0, (sizeof(int) * 26));
    }

    /* Iterate through the array and fill the lookup table */
    for(i = 0; i<wordsSize; i++) {
        for(j = 0; words[i][j] != '\0'; j++) {
            lookup[i][(words[i][j] - 'a')]++;
        }
    }

    /* Now iterate through the lookup table and find elements which occurs in    
     * all rows. Thre could be multiples, so take the min of it.
     */
    for(i=0; i<26; i++) {
        min_count = 0;
        for(j=0; j<wordsSize; j++) {
            if(lookup[j][i] == 0) {
                min_count = 0;
                break;
            } else if(lookup[j][i]) {
                if (min_count == 0) {
                     min_count = lookup[j][i];
                } else {
                     if (min_count > lookup[j][i]) {
                          min_count = lookup[j][i];
                     }
               }
            }
        }
        /* add the letter to the result if min_count has a value */
        for(k=0; k<min_count; k++) {
            ret[*returnSize] = (char *)malloc(sizeof(char) * 2);
            if(ret[*returnSize] == NULL) {
                // TODO: free memory
                return NULL;
            }
            ret[*returnSize][0] = i + 'a';
            ret[*returnSize][1] = '\0';
            *returnSize = *returnSize + 1;
        }
    }

    return ret;


}

