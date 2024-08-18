#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>



char** fizzBuzz(int n, int* returnSize) {

    char **ret;
    ret = (char **)malloc(sizeof(char *) * n);

    for(int i=1; i<=n; i++) {
        if((i%3==0) & (i%5 == 0)) {
            ret[i-1] = (char *)malloc(sizeof(char) * (strlen("FizzBuzz") + sizeof(char)));
            strncpy(ret[i-1], "FizzBuzz", (strlen("FizzBuzz") + 1));
        } else if((i%3==0)) {
            ret[i-1] = (char *)malloc(sizeof(char) * (strlen("Fizz") + sizeof(char)));
            strncpy(ret[i-1], "Fizz", (strlen("Fizz") + 1));
        } else if((i%5==0)) {
            ret[i-1] = (char *)malloc(sizeof(char) * (strlen("Buzz") + sizeof(char)));
            strncpy(ret[i-1], "Buzz", (strlen("Buzz") + 1));
        } else {
            ret[i-1] = (char *)malloc(sizeof(char) * (20 + sizeof(char)));
            snprintf(ret[i-1], 20, "%d",i);
        }
    }
    *returnSize = n;

    return ret;
    
}

int main() {

    int len = 0;
    char **str;
    str = fizzBuzz(15, &len);
    for(int i=0; i<len; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}