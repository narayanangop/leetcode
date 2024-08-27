#include<stdbool.h>

int comparefunc(const void *a, const void *b) {
    int *A = *((int **)a);
    int *B = *((int **)b);
    return (A[0] - B[0]);
}


bool canAttendMeetings(int** intervals, int intervalsSize, int* intervalsColSize) {

    if(intervalsSize <= 1)
        return true;

    qsort(intervals, intervalsSize, sizeof(intervals[0]), comparefunc);

    for(int i=1; i<intervalsSize; i++) {
        if(intervals[i][0] < intervals[i-1][1]) {
            return false;
        }
    }
    
    return true;
}