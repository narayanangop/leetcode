#include<stdbool.h>

bool isPerfectSquare(int num) {

    if(num <= 2)
        return true;

    int l = 2;
    int r = num >> 1;

    while(l <= r) {
        int m = l + ((r - l) / 2);
        long long guess = (long long)((long)m * (long)m);
        if(guess == num) {
            return true;
        }
        if(guess > num) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return false;
    
}