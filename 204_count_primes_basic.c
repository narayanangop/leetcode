#include<stdlib.h>
#include<stdbool.h>

bool is_prime(int n) {

    int i;
    if (n == 2)
        return true;

    if ((n % 2) == 0)
        return false;

    for(i=3; i<(n/2); i++) {
        if((n % i) == 0)
            return false;
    }

    return true;

}



int countPrimes(int n) {
    
    int i, res = 0;
    if(n <= 1)
        return 0;

    for(i=2; i<n; i++) {
        if(is_prime(i))
            res++;
    }

    return res;
}

