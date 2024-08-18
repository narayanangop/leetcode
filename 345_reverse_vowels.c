#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

bool isVowel(char c) {
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            return true;
    } else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            return true;
    }
    
    return false;
}

char* reverseVowels(char* s) {

    int l,r;
    char tmp;
    l=0;
    r=strlen(s) - 1;
    while(l<r) {
        if(!isVowel(s[l])) {
            l++;
            continue;
        }
        if(!isVowel(s[r])) {
            r--;
            continue;
        }

        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }

    return s;
    
}

int main() {
    char str[] = {"hellO"};
    printf("%s\n", reverseVowels(str));
    return 0;
}