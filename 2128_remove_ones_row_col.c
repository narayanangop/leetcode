#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

bool removeOnes(int** grid, int gridSize, int* gridColSize) {

    int i,j;
    int R,C;

    R = gridSize;
    C = gridColSize[0];

    if(R == 1 || C == 1)
        return true;

    for(i=1; i<R; i++) {
        if(grid[i][0] == grid[0][0]) {
            for(j=0; j<C; j++) {
                if(grid[i][j] != grid[0][j]) {
                    return false;
                }
            }
        } else {
            for(j=0; j<C; j++) {
                if(grid[i][j] != (grid[0][j]^0x01)) {
                    return false;
                }
            }
        }
    }

    return true;
    
}