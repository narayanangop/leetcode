#include<stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

char to_lower(char c) {
    if(c >= 'a' && c <= 'z') {
        return c;
    }
    
    return('a' + (c - 'A'));
}


char** findWords(char** words, int wordsSize, int* returnSize) {
    
    int map[] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};

    char **ret = (char **)malloc(sizeof(char *) * wordsSize);
    int retsize = 0;


    for(int i=0; i<wordsSize; i++) {
        int cur_row = -1;
        bool failed = false;
        for(int j=0; words[i][j] != '\0'; j++) {
            if(j == 0) {
                cur_row = map[(to_lower(words[i][j]) - 'a')];
            } else {
                if(map[(to_lower(words[i][j]) - 'a')] != cur_row) {
                    failed = true;
                    break;
                }
            }
        }
        if(!failed) {
            ret[retsize] = words[i];
            retsize++;
        }
    }
    *returnSize = retsize;

    return ret;

}