#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
typedef enum {
    ADD_CASE,
    REPLACE_CASE,
    REMOVE_CASE
} Case_t;

bool isOneEditDistance(char* s, char* t) {
    int ls = strlen(s);
    int lt = strlen(t);

    Case_t rule;
    rule = ADD_CASE;
    if(abs(ls - lt) > 1) {
        return false;
    }

    if(ls == lt) {
        rule = REPLACE_CASE;
    } else if (ls < lt) {
        rule = ADD_CASE;
    } else {
        rule = REMOVE_CASE;
    }

    int one_strike = 0;

    while(s || t) {

        if(s && t && *s == '\0' && *t == '\0') {
            break;
        }
        if(s && t && *s != '\0' && *t != '\0' && (*s == *t)) {
            s++;
            t++;
        } else {
            if(one_strike) {
                return false;
            }
            if(rule == REMOVE_CASE) {
                s++;
            } else if(rule == REPLACE_CASE) {
                s++;
                t++;
            } else {
                t++;
            }
            one_strike = 1;
        }
    }

    if(one_strike)
        return true;
    
    return false;
}