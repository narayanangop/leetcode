#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

char to_lower(char s) {
    if(s >= 'A' && s <= 'Z') {
        return((s - 'A') + 'a');
    }

    return s;
}

bool isvalid(char s) {

    if(s >= 'A' && s <= 'Z') {
        return true;
    } else if(s >= 'a' && s <= 'z') {
        return true;
    } else if(s >= '0' && s <= '9') {
        return true;
    }

    return false;
}

bool isPalindrome(char* s) {
    int l = 0;
    int r = strlen(s) - 1;

    while(l<r) {
        if(!isvalid(s[l])) {
            l++;
            continue;
        }
        if(!isvalid(s[r])) {
            r--;
            continue;
        }

        if(to_lower(s[l]) != to_lower(s[r]))
            return false;

        l++;
        r--;
    }

    return true;

}