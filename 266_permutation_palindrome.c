#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

bool canPermutePalindrome(char* s) {

    int mask = 0;
    while(s && *s != '\0') {
        int offset = 1 << (*s - 'a');
        mask = mask ^ offset;
        s++;
    }

    return((mask & (mask - 1)) == 0);
    
}

int main() {

    printf("%d\n", canPermutePalindrome("madma"));
    return 0;
}