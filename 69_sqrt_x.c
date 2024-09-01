int mySqrt(int x) {

    int l = 0;
    int r = x/2;
    long long m;
    
    if (x < 2) {
        return x;
    }
    
    while(l<=r) {
        m = l + (r - l)/2;
        long long guess = m * m;
        if(guess == x) {
            return m;
        } else if(guess < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return r;
   
}
