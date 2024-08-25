#include<stdbool.h>

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {

    int l,r,m;

    l = 0;
    r = (matrixSize * matrixColSize[0]) - 1;

    while(l <= r) {
        m = l + (r - l)/2;
        int mR = m / matrixColSize[0];
        int mC = m % matrixColSize[0];
        if(matrix[mR][mC] == target) {
            return true;
        } else if(matrix[mR][mC] > target) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return false;
    
}