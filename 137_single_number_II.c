int singleNumber(int* nums, int numsSize) {

    int seenonce = 0;
    int seentwice = 0;

    for(int i=0; i<numsSize; i++) {
        seenonce = (seenonce^nums[i]) & ~seentwice;
        seentwice = (seentwice^nums[i]) & ~seenonce;
    }

    return seenonce;
    
}