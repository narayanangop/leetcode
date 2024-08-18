#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

#define ALL_CAPS_RULE (1)
#define FIRST_CAPS_RULE (2)
#define ALL_SMALL_RULE  (3)

bool iscaps(char c) {
    if(c >= 'A' && c <= 'Z') {
        return true;
    }

    return false;
}


bool detectCapitalUse(char* word) {

    int len = strlen(word);
    int rule;
    if (len == 1)
        return true;
    if(iscaps(word[0]) && iscaps(word[1])) {
        rule = ALL_CAPS_RULE;
    } else if(iscaps(word[0]) && !iscaps(word[1])) {
        rule = FIRST_CAPS_RULE;
    } else if(!iscaps(word[0]) && !iscaps(word[1])) {
        rule = ALL_SMALL_RULE;
    } else if(!iscaps(word[0]) && iscaps(word[1])) {
        return false;
    }

    for(int i = 2; i<len; i++) {
        if(iscaps(word[i])) {
            if(rule == FIRST_CAPS_RULE || rule == ALL_SMALL_RULE) {
                return false;
            }
        } else {
            if(rule == ALL_CAPS_RULE) {
                return false;
            }
        }
    }
    
    return true;
}