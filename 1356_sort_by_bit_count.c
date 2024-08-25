/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int count_bits(int a) {
    int count = 0;
    while(a) {
        a = a & (a - 1);
        count++;
    }
    return count;
}

int comparefunc(void *a, void *b) {

    int A = *((int *)a);
    int B = *((int *)b);
    int cA = count_bits(A);
    int cB = count_bits(B);

    if(cA != cB) {
        return (cA - cB);
    }

    return (A - B);

}

int* sortByBits(int* arr, int arrSize, int* returnSize) {

    qsort(arr, arrSize, sizeof(int), comparefunc);
    *returnSize = arrSize;
    return arr;
    
}