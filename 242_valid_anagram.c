#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>


bool isAnagram(char* s, char* t) {

    int hash[26] = {0};

    while(s && *s != '\0') {
        hash[(*s - 'a')]++;
        s++;
    }

    while(t && *t != '\0') {
        if(hash[(*t - 'a')] != 0) {
            hash[(*t - 'a')]--;
        } else {
            return false;
        }
        t++;
    }

    for(int i = 0; i<26; i++) {
        if(hash[i] != 0)
            return false;
    }


    return true;
}

int main() {

    printf("%d\n", isAnagram("mirror", "rrorimm"));

    return 0;
}