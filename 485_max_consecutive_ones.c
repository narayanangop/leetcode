int findMaxConsecutiveOnes(int* nums, int numsSize) {

    int cur_max, max, i;
    cur_max = max = 0;

    for(i=0; i<numsSize; i++) {
        if(nums[i] == 1) {
            cur_max++;
        } else {
            cur_max = 0;
        }

        if(max < cur_max) {
            max = cur_max;
        }
    }

    return max;
    
}