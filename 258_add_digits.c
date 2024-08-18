#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

int addDigits(int num) {

    if(num == 0) {
        return 0;
    } else if ((num % 9) == 0) {
        return 9;
    }

    return(num % 9);   
}

int main() {

    printf("%d\n", addDigits(83));
    return 0;
}