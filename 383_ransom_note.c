#include<stdbool.h>

bool canConstruct(char* ransomNote, char* magazine) {

    int lookup[26] = {0};

    while(magazine && *magazine != '\0') {
        lookup[(*magazine - 'a')]++;
        magazine++;
    }

    while(ransomNote && *ransomNote != '\0') {
        if(lookup[(*ransomNote - 'a')] > 0) {
            lookup[(*ransomNote - 'a')]--;
        } else {
            return false;
        }
        ransomNote++;
    }

    return true;
    
}