int comparefunc(const void *a, const void *b) {
    return(*(int *)a - *(int *)b);
}

int majorityElement1(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), comparefunc);

    return(nums[numsSize/2]);
}



int majorityElement(int* nums, int numsSize) {

    /* just choose the first element as the candidate */
    int majority_element = nums[0];
    int count = 1;

    for(int i=1; i<numsSize; i++) {

        /* increment count if the new element is also the candidate */
        if(nums[i] == majority_element) {
            count++;
        } else {
            count--;
        }

        /* if the count is zero choose a new candidate */
        if(count == 0) {
            majority_element = nums[i];
            count = 1;
        }
    }

    return majority_element;
   
}



int majorityElement3(int* nums, int numsSize) {

    int majority = 0;
    unsigned int i;
    int count;

    /* loop through every bit in the integer */
    for(i=0; i < (sizeof(int) * 8); i++) {
        count = 0;
        for(int j=0; j<numsSize; j++) {
            /* this move the mask every outer loop as i gets incremented */
            if((nums[j] & (1u << i)) != 0) {
                 count++;
            }
        }

       /* if this bit is set in more than half of the elementes set the bit         
          in the result number */
        if (count > (numsSize >> 1)) {
            majority |= (1u << i);
        }
    }

    return majority;

   
}

