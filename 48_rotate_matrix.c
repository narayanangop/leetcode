#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

#define ROWS (3)
#define COLS (3)

void rotate(int** matrix, int matrixSize, int* matrixColSize) {

    int i,j,tmp,l,r;
    for(i=0; i<matrixSize; i++) {
        for(j=i; j<matrixColSize[0]; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for(i=0; i<matrixSize; i++) {
        l = 0;
        r = matrixColSize[0] - 1;
        while (l<r)
        {
            tmp = matrix[i][l];
            matrix[i][l] = matrix[i][r];
            matrix[i][r] = tmp;
            l++;
            r--;
        }
    }
   
}

int main() {
    int **matrix;
    int i,j;
    int count=0;
    matrix = (int **)malloc(sizeof(int *) * ROWS);
    for(i = 0; i < ROWS; i++) {
        matrix[i] = (int *)malloc(sizeof(int) * COLS);
    }
    for(i = 0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            matrix[i][j] = ++count;
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }
    count = ROWS;
    rotate(matrix, ROWS, &count);
    printf("---------------\n");
    for(i = 0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%d,", matrix[i][j]);
        }
        printf("\n");
    }


    return 0;
}