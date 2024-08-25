/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {

    int *ret = (int *)calloc((n+1), sizeof(int));
    *returnSize = (n+1);
 
    //beautiful dynamic programming here.
    for(int i=0; i<=n; i++) {
        ret[i] = ret[(i >> 1)] + (i & 0x01);
    }

    return ret;
    
}