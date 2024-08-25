/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** flipAndInvertImage(int** image, int imageSize, int* imageColSize, int* returnSize, int** returnColumnSizes) {

    int i,j;
    int l,r;
    int R, C;
    int tmp;

    R = imageSize;
    C = imageSize;
    *returnSize = imageSize;
    *returnColumnSizes = &imageColSize[0];
    for(i=0; i<R; i++) {
        l = 0;
        r = C - 1;
        while(l <= r) {
            if(l != r) {
                tmp = image[i][l];
                image[i][l] = image[i][r]^0x01;
                image[i][r] = tmp^0x01;
            } else {
                image[i][l] = image[i][l]^0x01;
            }
            l++;
            r--;
        }

    }

    return image;
    
}