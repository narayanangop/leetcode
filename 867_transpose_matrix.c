/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {

    int i,j,R,C;
    R=matrixSize;
    C=matrixColSize[0];
    int newRows, newCols;
    newRows = C;
    newCols = R;
    int **ret = (int **)malloc(sizeof(int *) * newRows);
    int *retcolsize = (int *)malloc(sizeof(int) * newRows);
    for(i=0; i<newRows; i++) {
        ret[i] = (int *)malloc(sizeof(int) * newCols);
        retcolsize[i] = newCols;
    }

    for(i=0; i<R; i++) {
        for(j=0; j<C; j++) {
            ret[j][i] = matrix[i][j];
        }
    }

    *returnColumnSizes = retcolsize;
    *returnSize = newRows;
    return ret;
    
}