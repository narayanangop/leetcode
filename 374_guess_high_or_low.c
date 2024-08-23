/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){

    int l = 1;
    int r = n;
    int m;

    while(l <= r) {
        m = l + (r - l)/2;
        int ret = guess(m);
        if(ret == 0) {
            return m;
        } else if (ret == -1) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return 0;
	
}