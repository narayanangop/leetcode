#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

int countSegments(char* s) {
    bool counted = false;
    int ret = 0;

    while(s && *s != '\0') {
        if(*s != ' ' && !counted) {
            ret++;
            counted = true;
        } else if(*s == ' ') {
            counted = false;
        }
        s++;
    }
    return ret;
}

int main() {

    printf("%d\n", countSegments("This is my life sorry  "));
    return 0;
}