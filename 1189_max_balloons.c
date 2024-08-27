#include<limits.h>

int maxNumberOfBalloons(char* text) {

    int text_freq[26] = {0};
    int pattern_freq[26] = {0};

    char pattern[] = "balloon";

    for(int i=0; i<strlen(pattern); i++) {
        pattern_freq[(pattern[i] - 'a')]++;
    }
    
    while(text && *text != '\0') {
        text_freq[(*text - 'a')]++;
        text++;
    }
    int min = INT_MAX;
    int cur;
    for(int i=0; i<26; i++) {
        if(pattern_freq[i])
            cur = text_freq[i]/pattern_freq[i];
        if(cur < min) {
            min = cur;
        }
    }


    return min;
}