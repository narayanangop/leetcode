#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

bool isPowerOfFour(int n) {

    if(n == INT_MIN || n == 0)
        return false;

    if((n & (n-1)) != 0)
        return false;

    if((n & 0xaaaaaaaa) != 0)
        return false;

    return true;
    
}