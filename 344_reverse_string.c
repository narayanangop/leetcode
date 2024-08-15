#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
 
 void reverseString(char* s, int sSize) {

    int l=0;
    int r=sSize-1;

    while(l<r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }

    return;    
    
}