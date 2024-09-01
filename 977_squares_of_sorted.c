#include<stdio.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {

    int l,r,m;
    l=0;
    r = numsSize - 1;
    while(l <= r) {
        printf("l = %d, r=%d\n", l, r);
        m = l + (r - l)/2;
        if(nums[m] < 0) {
            l = m + 1;
        } else if (nums[m] >= 0) {
            r = m - 1;
        }
    }

    printf("l = %d, r=%d\n", l, r);
    
}

int main() {

    int arr[] = {-8,-7,-9,-3,-1};
    int size = sizeof(arr)/ sizeof(int);
    int ret;

    sortedSquares(arr, size, &ret);
}
 

