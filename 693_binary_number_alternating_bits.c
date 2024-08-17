#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

bool hasAlternatingBits(int n) {

    long x = n;
    x = x + (x >> 1);
    x = x + 1;

    return ((x & (x - 1)) == 0);
}