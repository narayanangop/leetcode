#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

int myAtoi(char* s) {

    int res = 0;
    int digit;
    int sign=0;

    while(s && *s == ' ') {
        s++;
    }

    if(s && *s == '-') {
        sign = 1;
        s++;
    } else if(s && *s == '+') {
        s++;
    }

    while(s && *s != '\0') {
        if(*s < '0' || *s > '9') {
            break;
        }
        digit = *s - '0';
        if(!sign) {
            if(res > INT_MAX/10)
                return INT_MAX;
            if(INT_MAX/10 == res) {
                if (digit > 7)
                    return INT_MAX;
            }
        } else {
            if(res < INT_MIN/10)
                return INT_MIN;
            if(INT_MIN/10 == res) {
                if (digit > 8)
                    return INT_MIN;
            }
        }

        if (res != 0) {
            if (!sign)
                res = (res * 10) + digit;
            else
                res = (res * 10) - digit;
        } else {
            if(digit != 0) {
                if(sign) {
                    res = -digit;
                } else {
                    res = digit;
                }
            }
        }
           
        s++;
    }

    return res;
    
}

int main() {
    printf("%d\n", myAtoi("123"));
    printf("%d\n", myAtoi("+99"));
    printf("%d\n", myAtoi("    123456"));
    printf("%d\n", myAtoi("    -755ab"));
    printf("%d\n", myAtoi("2147483647"));
    printf("%d\n", myAtoi(" -2147483648"));
    printf("%d\n", myAtoi("21474836476"));
    printf("%d\n", myAtoi(" -21474836468"));
    printf("%d\n", myAtoi("0"));
    printf("%d\n", myAtoi("000"));
    printf("%d\n", myAtoi("   -000ab"));
    printf("%d\n", myAtoi("-+12"));
    printf("%d\n", myAtoi("-042"));
    
    return 0;
}