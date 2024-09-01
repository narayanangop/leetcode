int rangeBitwiseAnd(int left, int right) {

    int count = 0;
    while(left < right) {
        left >>= 1;
        right >>= 1;
        count ++;
    }
    return(1 << count);

}

int rangeBitwiseAnd(int left, int right) {

    while(left < right) {
       right = right & (right - 1);
    }

    return right;

}
