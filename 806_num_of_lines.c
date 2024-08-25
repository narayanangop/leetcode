

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char * s, int* returnSize){

    int line_count = 0;
    int cur_count = 0;

    while(s && *s != '\0') {
        int pixel = widths[(*s - 'a')];
        if((pixel + cur_count) <= 100) {
            cur_count += pixel;
        } else {
            line_count++;
            cur_count = pixel;
        }
        s++;
    }

    if(cur_count) {
        line_count++;
    }

    int *ret = (int *)malloc(sizeof(int) * 2);
    ret[0] = line_count;
    ret[1] = cur_count;

    *returnSize = 2;

    return ret;

}