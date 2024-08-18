#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

void myreverse(char *s, int l , int r) {

    char tmp;
    while(l<r) {
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}


void reverseWords(char* s, int sSize) {

    int j=0;
    for(int i=0; i<sSize; i++) {
        if(s[i] == ' ') {
            myreverse(s, j, (i-1));
            j = i + 1;
        } else if(i == (sSize - 1)) {
            myreverse(s, j, i);
        }
    }

    myreverse(s, 0, (sSize - 1));
    
}

int main() {

    char a[] = {'t','h','e',' ','s','k','y',' ','i','s',' ','b','l','u','e'};
    for(int i=0; i<sizeof(a); i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
    reverseWords(a, sizeof(a));
    for(int i=0; i<sizeof(a); i++) {
        printf("%c ", a[i]);
    }
    printf("\n");
    return 0;
}