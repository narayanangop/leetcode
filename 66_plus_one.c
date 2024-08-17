#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {

    for(int i=digitsSize-1; i>=0; i--) {
        if(digits[i] == 9) {
            digits[i] = 0;
        } else {
            digits[i] = ++digits[i];
            *returnSize = digitsSize;
            return digits;
        }
    }

    int *ret = (int *)malloc(sizeof(int) * (digitsSize + 1));
    memset(ret, 0, sizeof(int) * (digitsSize + 1));
    ret[0] = 1;
    *returnSize = digitsSize + 1;

    return ret;
    
}


int main() {

    int a[] = {9,9,9};
    int len = sizeof(a)/sizeof(a[0]);
    int *b;
    b = plusOne(a, len, &len);
    
    for(int i=0; i<len; i++) {
        printf("%d,", b[i]);
    }

    printf("\n");

    return 0;
}

