




int removeDuplicates(int* nums, int numsSize) {

    if(numsSize == 1) 
        return 1;
    
    int running_num = nums[0];
    int j = 1;
    for(int i = 1; i<numsSize; i++) {

        if(nums[i] == running_num) 
            continue;
        
        nums[j] = nums[i];
        j++;
        running_num = nums[i];

    }

    return j;
    
}


int main() {

    int a[] = {1,1,1,2,2,2,3,3,4,5,5,6,8,8,8,23,23,44};
    int len = sizeof(a)/sizeof(a[0]);
    len = removeDuplicates(a, len);

    for(int i=0; i<len; i++) {
        printf("%d,", a[i]);
    }

    printf("\n");

    return 0;
}