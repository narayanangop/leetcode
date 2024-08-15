int strStr(char* haystack, char* needle) {

    int haylen = strlen(haystack);
    int needle_len = strlen(needle);

    int i,j;
    int mismatch;

    for(i=0; i<haylen; i++) {
        if((i+needle_len) > haylen) {
            return -1;
        }
        mismatch = 0;
        for(j=0; j<needle_len; j++) {
            if(haystack[i+j] != needle[j]) {
                mismatch = 1;
                break;
            }


        }
        if(mismatch == 0) {
            return i;
        }
    }

    return -1;
    
}