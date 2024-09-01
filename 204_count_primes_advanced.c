int countPrimes(int n) {

    char *flag = (char *)malloc(sizeof(char) * n);
    memset(flag, 0x01, (n * sizeof(char)));

    if (n < 2)
        return 0;

    int i,j;
    i = 2;
    j = 0;

    while((i * i) < n) {

       if(flag[i]) {
           for(j = (i*i); j<n; j+=i) {
                flag[j] = 0;
           }
       }
    i++;
    }

    int res = 0;
    for(i = 2; i<n; i++)
        res += flag[i];


    return res;
    
    
}

