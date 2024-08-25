

int countConsistentStrings(char * allowed, char ** words, int wordsSize){

    int ret = 0;
    unsigned int allowed_mask = 0;
    while(allowed && *allowed != '\0') {
        allowed_mask = allowed_mask | (1 << (*allowed - 'a'));
        allowed++;
    }

    for(int i = 0; i<wordsSize; i++) {
        int cur_mask = 0;
        int j=0;

        while(words[i][j] != '\0') {
            cur_mask = cur_mask | (1 << (words[i][j] - 'a'));
            j++;
        }
        if((cur_mask | allowed_mask) == allowed_mask) {
            ret++;
        }
    }

    return ret;

}