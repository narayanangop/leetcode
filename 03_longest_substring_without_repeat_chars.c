#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<string.h>

int max(int a, int b) {
    return ((a > b) ? a : b);
}

int lengthOfLongestSubstring(char* s) {

    int len = strlen(s);
    int left, right, current_count, max_count;
    int map[256] = {0};
    int index = 0;
    left = 0;
    current_count = max_count = 0;
    for(right = 0; right < len; right++) {
        index = (int)s[right];
        if(map[index] > 0) {
            left = max(left, map[index]);            
        }
        current_count = right - left + 1;
        if(current_count >= max_count) {
            max_count = current_count;
        }

        map[index] = right + 1;

    }

    return max_count;
    
}

int lengthOfLongestSubstring_bruteforce(char* s) {

    char map[256];
    int current_count, max_count;
    current_count = max_count = 0;
    while (s && *s != '\0') {
        memset(map, 0, 256);
        current_count = 0;
        char *s1 = s;
        while(s1 && *s1 != '\0') {
            if(map[(int)*s1]) {
                break;
            }
            current_count++;
            if(current_count >= max_count) {
                max_count = current_count;
            }
            map[(int)*s1] = 1;
            s1++;
        }
        s++;
    }

    return max_count;
    
}


int main() {
    printf("ans for \"abcabcbb\" %d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("ans for \"abcabcbb\" %d\n", lengthOfLongestSubstring_bruteforce("abcabcbb"));
    return 0;
}

