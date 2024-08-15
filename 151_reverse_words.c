#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>
#include<string.h>

void mystrrev(char *s, int l, int r) {
    char tmp;
    while(l < r) {
        tmp = s[l];
        s[l] = s[r];
        s[r] = tmp;
        l++;
        r--;
    }
}

char* reverseWords(char* s) {

    while(s && *s != '\0') {
        if(*s == ' ') {
            s++;
        } else {
            break;
        }
    }

    int i, j, first_space_crossed;
    int len = strlen(s);
    first_space_crossed = 0;
    j=0;
    for(i=0; i<len; i++) {
        if(s[i] == ' ' && first_space_crossed) {
            continue;
        } else  {
            s[j] = s[i];
            j++;
            if(s[i] == ' ') {
                first_space_crossed = 1;
            } else {
                first_space_crossed = 0;
            }
        }
    }
    if(j != 0 && s[j-1] == ' ') {
        s[j-1] = '\0';
    } else {
        s[j] = '\0';
    }
    len = strlen(s);
    for(i=0, j=0; i<=len; i++) {
        if(s[i] == ' ' || s[i] == '\0') {
            mystrrev(s, j, (i-1));
            j = i+1;
        }
    }
    mystrrev(s, 0, (len-1));

    return s;
    
}

int main() {
    char *buffer = (char *)malloc(sizeof(char) * 100);
    strncpy(buffer, "    life   is good   ", 100);
    printf("%s\n", reverseWords(buffer));
    strncpy(buffer, "oneword", 100);
    printf("%s\n", reverseWords(buffer));
    strncpy(buffer, "     ", 100);
    printf("%s\n", reverseWords(buffer));
    strncpy(buffer, "", 100);
    printf("%s\n", reverseWords(buffer));
    strncpy(buffer, "the sky is blue", 100);
    printf("%s\n", reverseWords(buffer));
    
    return 0;
}