int comparefunc(void *a, void *b) {
    int A = *((int *)a);
    int B = *((int *)b);

    return(A - B);
}

int largestUniqueNumber(int* nums, int numsSize) {

    qsort(nums, numsSize, sizeof(int), comparefunc);
    int current_num = nums[numsSize - 1];
    int current_count = 1;
    for(int i=0; i<numsSize; i++) {
        printf("%d,",nums[i]);
    }
    for(int i=numsSize-2; i>=0; i--) {
        if(nums[i] != current_num && current_count == 1) {
            return current_num;
        } else if (nums[i] == current_num){
            current_count++;
        } else {
            current_num = nums[i];
            current_count = 1;
        }
    }

    if(current_count == 1)
        return current_num;

    return -1;
    
}