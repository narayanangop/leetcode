int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {

    int l = 0;
    int r = numsSize - 1;
    int tmp;
    while(l < r) {

        if (((nums[l] & 0x01) == 0) && ((nums[r] & 0x01) == 1)) {
            l++;
            r--;
        } else if (((nums[l] & 0x01) == 1) && ((nums[r] & 0x01) == 0)) {
            tmp = nums[l];
            nums[l] = nums[r];
            nums[r] = tmp;
            l++;
            r--;
        } else if ((nums[r] & 0x01) == 1) {
            r--;
        } else if ((nums[l] & 0x01) == 0) {
            l++;
        }
    }

    *returnSize = numsSize;
    return nums;
   
}
