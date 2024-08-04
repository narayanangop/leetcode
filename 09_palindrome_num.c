#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

bool isPalindrome(int x) {

    if(x < 0)
        return false;

    int tmp, new_num;
    tmp = x;

    new_num = 0;
    while (tmp > 0)
    {
        if(new_num > INT_MAX/10)
            return false;
        if(INT_MAX/10 == new_num) {
            if ((tmp % 10) > 7)
                return false;
        }
        new_num = (new_num * 10) + (tmp % 10);
        tmp /= 10;
    }

    return(new_num == x);
    

}

int main() {

    for(int i=INT_MAX; i>0; i--) {
        if(isPalindrome(i)) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}