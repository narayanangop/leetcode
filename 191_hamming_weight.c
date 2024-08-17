#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>


int hammingWeight(int n) {

    int count = 0;
    while(n != 0) {
        n = n & (n-1);
        count++;
    }

    return count;
    
}

int main() {

    printf("%d\n", hammingWeight(0xffff));
    printf("%d\n", hammingWeight(8));
    printf("%d\n", hammingWeight(7));
    printf("%d\n", hammingWeight(0));
    printf("%d\n", hammingWeight(255));

    return 0;
}