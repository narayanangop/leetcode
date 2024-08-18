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

    int i;
    int len = strlen(s);
    int p1 = 0;
    for(i=0; i<len; i++) {

        if(s[i] == ' ') {
            mystrrev(s, p1, (i - 1));
            p1 = i+1;
        } else if(i == (len - 1)) {
            mystrrev(s, p1, i);
        }

    }

    return s;
    
}