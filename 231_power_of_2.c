#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

bool isPowerOfTwo(int n) {

    if (n == 0)
        return false;
    long x = n;
    return ((x & (x-1)) == 0);
    
}