#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

char *mystrrev(char *s) {
    int l = 0;
    int r = strlen(s) - 1;

    while(l<r) {
        char tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }

    return s;
}

char* toHex(int num) {

    char *str = (char *)malloc(sizeof(char) * ((sizeof(int) * 2) + 1));
    int index = 0;
    int nibble;

    // remember the do-while here. needed to handle the zero case.
    do {
        nibble = num & 0xf;
        if(nibble <= 9) {
            str[index] = '0' + nibble;
        } else if(nibble > 9) {
            str[index] = 'a' + (nibble - 10);
        }
        index++;
        //remember we are doing a logic rightshift here by casting into a unsigned int.
        num = (unsigned int)num >> 4;
    } while(num);
    str[index] = '\0';

    return(mystrrev(str));
    
}

int main() {

    printf("%s\n", toHex(-255));
}