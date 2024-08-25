/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoOutOfThree(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* returnSize) {

    char lookup[101] = {0};
    int i;

    for(i=0; i<nums1Size; i++) {
        lookup[(nums1[i])] = lookup[(nums1[i])] | 0x01;
    }

    for(i=0; i<nums2Size; i++) {
        lookup[(nums2[i])] = lookup[(nums2[i])] | (1 << 1);
    }

    for(i=0; i<nums3Size; i++) {
        lookup[(nums3[i])] = lookup[(nums3[i])] | (1 << 2);
    }

    int *ret = (int *)malloc(sizeof(int) * 101);
    int index = 0;
    for(i = 0; i<101; i++) {
        if(lookup[i] == 3 || lookup[i] == 7 || lookup[i] == 5 || lookup[i] == 6) {
            ret[index++] = i;
        }
    }

    *returnSize = index;
    return ret;
    
}