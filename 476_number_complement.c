int findComplement(int num) {
    
    int mask = num;
    // create a mask from the left most set bit.
    mask = mask | (mask >> 1);
    mask = mask | (mask >> 2);
    mask = mask | (mask >> 4);
    mask = mask | (mask >> 8);
    mask = mask | (mask >> 16);

    return(num^mask);
}