#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>


int missingNumber(int* nums, int numsSize) {
    
    int missing = 0;
    int i;
    for(i=0; i<numsSize; i++) {
        missing = missing^nums[i];
        missing = missing^i;
    }
    missing = missing^numsSize;
    return missing;
}

int main() {

    int a[] = {9,6,4,2,3,5,7,0,1};
    printf("%d\n",missingNumber(a, (sizeof(a)/sizeof(a[0]))));
}
