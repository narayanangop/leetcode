int lengthOfLastWord(char* s) {
    
    int len = strlen(s);
    int ret = 0;

    for(int i=len-1; i>=0; i--) {
        if(s[i] == ' ' && ret == 0) {
            continue;
        } else if (s[i] == ' ') {
            return ret;
        }

        ret++;
    }

    return ret;
}