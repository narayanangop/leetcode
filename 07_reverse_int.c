#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

int reverse(int x){

    int rev_num = 0;

    while(x != 0) {
        int digit = x % 10;
        if(rev_num > INT_MAX/10) {
            return 0;
        }
        if(INT_MAX/10 == rev_num) {
            if(digit > 7)
            return 0;
        }
        if(rev_num < INT_MIN/10) {
            return 0;
        }
        if(INT_MIN/10 == rev_num) {
            if(digit < -8) {
                return 0;
            }
        }
        rev_num = rev_num * 10 + digit;
        x /= 10;
    }
    return rev_num;

}

int main() {
    printf("rev num of 123 = %d\n", reverse(123));
    printf("rev num of -123 = %d\n", reverse(-123));
    printf("rev num of %d = %d\n", INT_MAX, reverse(INT_MAX));
    printf("rev num of %d = %d\n", INT_MIN, reverse(INT_MIN));
    return 0;
}