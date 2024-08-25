int removeDuplicates(int* nums, int numsSize) {

    int prev, prev_count, i;

    prev = nums[0];
    prev_count = 1;
    int p1 = 1;
    for(i=1; i<numsSize; i++) {
        if(nums[i] == prev) {
            if(prev_count < 2) {
                nums[p1++] = nums[i];
                prev_count++;
            }
        } else {
            prev = nums[i];
            prev_count = 1;
            nums[p1++] = nums[i];
        }
    }

    return p1;
    
}