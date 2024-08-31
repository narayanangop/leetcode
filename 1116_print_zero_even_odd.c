#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

void printNumber(int n) {
    printf("%d", n);
}


typedef struct {
    int n;
    int cur;
    sem_t semzero;
    sem_t semodd;
    sem_t semeven;
} ZeroEvenOdd;

ZeroEvenOdd* zeroEvenOddCreate(int n) {
    ZeroEvenOdd* obj = (ZeroEvenOdd*) malloc(sizeof(ZeroEvenOdd));
    obj->n = n;
    obj->cur = 1;
    sem_init(&obj->semzero, 0, 1);
    sem_init(&obj->semodd, 0, 0);
    sem_init(&obj->semeven, 0, 0);
    return obj;
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.

void zero(ZeroEvenOdd* obj) {
    while(1) {
        sem_wait(&obj->semzero);
        if(obj->cur > obj->n)
            break;
        printNumber(0);
        if(obj->cur & 0x01) {
            sem_post(&obj->semodd);
        } else {
            sem_post(&obj->semeven);
        }
    }
    sem_post(&obj->semodd);
    sem_post(&obj->semeven);
}

void even(ZeroEvenOdd* obj) {
    while(1) {
        sem_wait(&obj->semeven);
        if(obj->cur > obj->n)
            break;
        printNumber(obj->cur);
        obj->cur++;
        sem_post(&obj->semzero);
    }
}

void odd(ZeroEvenOdd* obj) {
    while(1) {
        sem_wait(&obj->semodd);
        if(obj->cur > obj->n)
            break;
        printNumber(obj->cur);
        obj->cur++;
        sem_post(&obj->semzero);
    }
}

void zeroEvenOddFree(ZeroEvenOdd* obj) {

    sem_destroy(&obj->semzero);
    sem_destroy(&obj->semeven);
    sem_destroy(&obj->semodd);
    free(obj);

}

int main() {
    pthread_t eventhread, oddthread, zerothread;
    ZeroEvenOdd *data;
    data = zeroEvenOddCreate(5);
    pthread_create(&zerothread, NULL, (void * (*) (void *))zero, (void *) data);
    pthread_create(&oddthread, NULL, (void * (*) (void *))odd, (void *) data);
    pthread_create(&eventhread, NULL, (void * (*) (void *))even, (void *) data);

    pthread_join(eventhread, NULL);
    pthread_join(oddthread, NULL);
    pthread_join(zerothread, NULL);
    return 0;
}

