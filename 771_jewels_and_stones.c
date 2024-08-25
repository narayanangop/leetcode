int numJewelsInStones(char* jewels, char* stones) {
    
    int jlookup[128] = {0};

    while(jewels && *jewels != '\0') {
        jlookup[*jewels] = 1;
        jewels++;
    }

    int ret = 0;
    while(stones && *stones != '\0') {
        if(jlookup[(*stones)] == 1) {
            ret++;
        }
        stones++;
    }

    return ret;
}