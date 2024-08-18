#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>


void moveZeroes(int* nums, int numsSize) {
    int i,j;
    i=0; j = 0;

    for(i=0; i<numsSize; i++) {
        if(nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    while(j<numsSize) {
        nums[j] = 0;
        j++;
    }
    
}

int main() {

    int a[] = {0,0,9,9,9};
    int len = sizeof(a)/sizeof(a[0]);
    moveZeroes(a, len);
    
    for(int i=0; i<len; i++) {
        printf("%d,", a[i]);
    }

}