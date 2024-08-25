
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>


char* addBoldTag(char* s, char** words, int wordsSize) {

    char *mask = (char *)calloc(strlen(s), sizeof(char));
    int len = strlen(s);

    int i;
    char *offset;

    for(i=0; i<wordsSize; i++) {
        char *s2 = s;
        while(1) {
            offset = strstr(s2, words[i]);
            if(offset == NULL) {
                break;
            }
            memset((mask + (offset - s)), 1, strlen(words[i]));
            s2 = offset + 1;
        }
    }

    char *ret = (char *)malloc(len * sizeof(char) * 8);
    int p1 = 0;
    bool bold_in_progress = false;
    for(i=0; i<len; i++) {
        if(mask[i] == 1) {
            if(!bold_in_progress) {
                bold_in_progress = true;
                ret[p1++] = '<';
                ret[p1++] = 'b';
                ret[p1++] = '>';
                ret[p1++] = s[i];
            } else {
                ret[p1++] = s[i];
            }
        } else {
                if(bold_in_progress) {
                    bold_in_progress = false;
                    ret[p1++] = '<';
                    ret[p1++] = '/';
                    ret[p1++] = 'b';
                    ret[p1++] = '>';
                    ret[p1++] = s[i];
                } else {
                    ret[p1++] = s[i];
                }
        }
    }

    if(bold_in_progress) {
        bold_in_progress = false;
        ret[p1++] = '<';
        ret[p1++] = '/';
        ret[p1++] = 'b';
        ret[p1++] = '>';
    }

    ret[p1++] = '\0';

    return ret;
    
}