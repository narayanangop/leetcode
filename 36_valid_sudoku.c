#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>


int getboxnum(int r, int c) {

    int row_blk;
    int col_blk;

    row_blk = r/3;
    col_blk = c/3;

    return col_blk + (3 * row_blk);
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize) {

    int r,c;
    int i,j;
    r=boardSize;
    c=*boardColSize;

    int row_hash[10][10] = {0};
    int col_hash[10][10] = {0};
    int box_hash[9][10] = {0};
    //printf("%d %d\n", r,c);
    for(i=0; i<r; i++) {

        for(j=0; j<c; j++) {

            int box_num = getboxnum(i,j);
            //printf("%d ", box_num);
            if(board[i][j] == '.') 
                continue;
            int val = board[i][j] - '0';

            if(row_hash[i][val]) {
                return false;
            }
            row_hash[i][val] = 1;

            if(col_hash[j][val]) {
                return false;
            }
            col_hash[j][val] = 1;

            if(box_hash[box_num][val]) {
                return false;
            }
            box_hash[box_num][val] = 1;

        }

        //printf("\n");
    }

    return true;
    
}

int main() {
    char arr[9][9] = {{'5','3','.','.','7','.','.','.','.'},
                     {'6','.','.','1','9','5','.','.','.'},
                     {'.','9','8','.','.','.','.','6','.'},
                     {'8','.','.','.','6','.','.','.','3'},
                     {'4','.','.','8','.','3','.','.','1'},
                     {'7','.','.','.','2','.','.','.','6'},
                     {'.','6','.','.','.','.','2','8','.'},
                     {'.','.','.','4','1','9','.','.','5'},
                     {'.','.','.','.','8','.','.','7','9'}};

    int rows = sizeof(arr) / sizeof(arr[0]);
    int cols = sizeof(arr[0]) / sizeof(arr[0][0]);

    char *ptr[rows];
    for (int i = 0; i < rows; i++) {
        ptr[i] = arr[i];
    }

    printf("result = %d\n", isValidSudoku(ptr, rows, &cols));

    return 0;
}