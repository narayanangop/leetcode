int maxIncreaseKeepingSkyline(int** grid, int gridSize, int* gridColSize) {

    int *rowmax = (int *)malloc(sizeof(int) * gridSize);
    int *colmax = (int *)malloc(sizeof(int) * gridSize);

    int R, C, i, j;
    R = C = gridSize;
    int ret = 0;

    for(i=0; i<R; i++) {
        rowmax[i] = colmax[i] = -1;
    }

    for(i=0; i<R; i++) {
        for(j=0; j<C; j++){
            if(grid[i][j] > rowmax[i]) {
                rowmax[i] = grid[i][j];
            }
            if(grid[i][j] > colmax[j]) {
                colmax[j] = grid[i][j];
            }
        }
    }

    for(i=0; i<R; i++) {
        for(j=0; j<C; j++) {
            int max;
            if(rowmax[i] < colmax[j]) {
                max = rowmax[i];
            } else {
                max = colmax[j];
            }
            ret += (max - grid[i][j]);
        }
    }

    return ret;
    
}