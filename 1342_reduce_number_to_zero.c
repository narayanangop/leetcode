int numberOfSteps(int num) {

    if(num == 0) {
        return 0;
    }
    int mask = 1;
    int steps = 0;
    while(mask <= num) {
        if(mask & num) {
            steps += 2;
        } else {
            steps += 1;
        }
        mask <<= 1;
    }

    return (steps - 1);
    
}