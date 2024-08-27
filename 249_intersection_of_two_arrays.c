/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int comparefunc(void *a, void *b) {
    int A = *((int *)a);
    int B = *((int *)b);

    return(A - B);
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    qsort(nums1, nums1Size, sizeof(int), comparefunc);
    qsort(nums2, nums2Size, sizeof(int), comparefunc);

    int *ret = (int *)malloc(sizeof(int) * ((nums1Size < nums2Size) ? nums1Size:nums2Size));
    int index=0;
    int i,j;
    i=0;
    j=0;

    while((i < nums1Size) && (j < nums2Size)) {
        //printf("%d %d\n", nums1[i], nums2[j]);
        if(nums1[i] == nums2[j]) {
            if((index == 0) || (ret[index - 1] != nums1[i])) {
                ret[index++] = nums1[i];
            }
            i++;
            j++;
        } else if(nums1[i] < nums2[j]) {
            i++;
        } else {
            j++;
        }
    }


    *returnSize = index;
    return ret;
    
}