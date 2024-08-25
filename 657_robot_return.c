
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

bool judgeCircle(char* moves) {

    int x=0;
    int y=0;

    while(moves && *moves != '\0') {
        switch(*moves) {
            case 'U':
                y++;
                break;
            case 'D':
                y--;
                break;
            case 'L':
                x--;
                break;
            case 'R':
                x++;
                break;
            default:
                break;
        }
        moves++;
    }

    return((x == 0) && (y == 0));
    
}