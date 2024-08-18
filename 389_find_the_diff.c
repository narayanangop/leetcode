char findTheDifference(char* s, char* t) {

    char xor=0;

    while(s && *s != '\0') {
        xor = xor^*s;
        s++;
    }

    while(t && *t != '\0') {
        xor = xor^*t;
        t++;
    }

    return xor;
    
}