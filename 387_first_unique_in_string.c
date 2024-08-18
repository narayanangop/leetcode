#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

int firstUniqChar(char* s) {
    int lookup[26] = {0};
    int len = strlen(s);
    int i;

    for(i=0; i<len; i++) {
        lookup[(s[i] - 'a')]++;
    }

    for(i=0; i<len; i++) {
        if(lookup[(s[i] - 'a')] == 1) {
            return i;
        }
    }

    return -1;
}

int main() {

    printf("%d\n",firstUniqChar("leetcodeleetcode"));
    return 0;
}