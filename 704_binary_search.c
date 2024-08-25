int search(int* nums, int numsSize, int target) {

    int l=0;
    int r = numsSize - 1;

    while(l <= r) {
        int m = l + (r - l)/2;
        if(target == nums[m]) {
            return m;
        }
        if(target > nums[m]) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }

    return -1;
    
}