#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>


#define FIVES (0)
#define TENS (1)
#define TWENTYS (2)
bool lemonadeChange(int* bills, int billsSize) {

    int cash_drawer[3] = {0};
    int i;

    for(i=0; i<billsSize; i++) {
        int change = bills[i] - 5;
        if(change == 15) {
            cash_drawer[TWENTYS]++;
            if(cash_drawer[FIVES] > 0 && cash_drawer[TENS] > 0) {
                cash_drawer[FIVES]--;
                cash_drawer[TENS]--;
            } else if(cash_drawer[FIVES] >= 3) {
                cash_drawer[FIVES] -= 3;
            } else {
                return false;
            }
        }
        else if(change == 5) {
            cash_drawer[TENS]++;
            if(cash_drawer[FIVES] >= 1) {
                cash_drawer[FIVES]--;
            } else {
                return false;
            }
        } else {
            cash_drawer[FIVES]++;
        }
    }

    return true;
    
}