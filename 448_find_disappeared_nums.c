#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    int i, *ret, index;
    ret = (int *)malloc(sizeof(int) * numsSize);

    for(i=1; i<=numsSize; i++) {
        index = abs(nums[i-1]) - 1;
        if(nums[index] > 0) {
            nums[index] = -nums[index];
        }
    }
    index = 0;
    for(i=0; i<numsSize; i++) {
        if(nums[i] > 0) {
            ret[index] = i+1;
            index++;
        }
    }

    *returnSize = index;
    return ret;
    
}