

void mystrrev(int *nums, int l, int r) {

    int tmp;
    while(l < r) {
        tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
    }

}

void rotate(int* nums, int numsSize, int k){

    /* if you are going one full rotation, you can ignore that */
    if(k > numsSize) {
        k = k % numsSize;
    }

    if(k == 0)
        return;

    /* reverse the entire array. and reverse the small-subarrays */
    mystrrev(nums, 0, (numsSize - 1));
    mystrrev(nums, 0, (k - 1));
    mystrrev(nums, k, (numsSize - 1));

}



void rotate(int* nums, int numsSize, int k){


    int i, j;
    /* Allocate space for extra array */
    int *ret = (int *)malloc(sizeof(int) * numsSize);

    if (k > numsSize) {
        k = k % numsSize;
    }

    if (k == 0)
        return;
    j=0;
    for(i=0; i<k; i++) {
        ret[j++] = nums[(numsSize - k) + i];
    }

    for(i=0; i<(numsSize - k); i++) {
        ret[j++] = nums[i];
    }
    for(i=0; i<numsSize; i++) {
         nums[i] = ret[i];
    }

    free(ret);
}

