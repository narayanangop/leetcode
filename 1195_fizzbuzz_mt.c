#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

// Functions to print fizz, buzz, fizzbuzz, and numbers
void printFizz() {
    printf("fizz\n");
}

void printBuzz() {
    printf("buzz\n");
}

void printFizzBuzz() {
    printf("fizzbuzz\n");
}

void printNumber(int num) {
    printf("%d\n", num);
}


typedef struct {
    int n;
    int cur;
    sem_t sem_num;
    sem_t sem_fizz;
    sem_t sem_buzz;
    sem_t sem_fizzbuzz;
} FizzBuzz;

FizzBuzz* fizzBuzzCreate(int n) {
    FizzBuzz* obj = (FizzBuzz*) malloc(sizeof(FizzBuzz));
    obj->n = n;
    obj->cur = 1;

    /* Initalize all the semaphores with 0 except for the
     * Except for the num semaphore as we start with that*/
    sem_init(&obj->sem_num, 0, 1);
    sem_init(&obj->sem_fizz, 0, 0);
    sem_init(&obj->sem_buzz, 0, 0);
    sem_init(&obj->sem_fizzbuzz, 0, 0);
    return obj;
}

// printFizz() outputs "fizz".
void fizz(FizzBuzz* obj) {

    while(1) {
        /* wait till it is your turn */
        sem_wait(&obj->sem_fizz);
        if(obj->cur <= obj->n) {
            printFizz();
            obj->cur++;
            /* once printing is done signal the waiting number thread*/
            sem_post(&obj->sem_num);
        } else {
            /* If we done printing everything exit*/
            break;
        }
    }
    
}

// printBuzz() outputs "buzz".
void buzz(FizzBuzz* obj) {
    while(1) {
        /* wait till it is your turn */
        sem_wait(&obj->sem_buzz);
        if(obj->cur <= obj->n) {
            printBuzz();
            obj->cur++;
            /* once printing is done signal the waiting number thread*/
            sem_post(&obj->sem_num);
        } else {
            /* If we done printing everything exit*/
            break;
        }
    }
}

// printFizzBuzz() outputs "fizzbuzz".
void fizzbuzz(FizzBuzz* obj) {

    while(1) {
        /* wait till it is your turn */
        sem_wait(&obj->sem_fizzbuzz);
        if(obj->cur <= obj->n) {
            printFizzBuzz();
            obj->cur++;
            /* once printing is done signal the waiting number thread*/
            sem_post(&obj->sem_num);
        } else {
            /* If we done printing everything exit*/
            break;
        }
    }    
}

// You may call global function `void printNumber(int x)`
// to output "x", where x is an integer.
void number(FizzBuzz* obj) {
    
    /* the number thread is the master thread for the syncronization
     * waits of the other thread to finish and signal except when start
     * the semaphore is already available */
    while (1)
    {
        sem_wait(&obj->sem_num);
        if(obj->cur > obj->n)
            break;
        if((obj->cur % 3 == 0) && (obj->cur % 5 == 0)) {
            sem_post(&obj->sem_fizzbuzz);
        } else if ((obj->cur % 3 == 0)) {
            sem_post(&obj->sem_fizz);
        } else if ((obj->cur % 5 == 0)) {
            sem_post(&obj->sem_buzz);
        } else {
            printNumber(obj->cur);
            obj->cur++;
            sem_post(&obj->sem_num);
        }
        
    }
    sem_post(&obj->sem_fizzbuzz);
    sem_post(&obj->sem_fizz);
    sem_post(&obj->sem_buzz);
    
}

void fizzBuzzFree(FizzBuzz* obj) {

    sem_destroy(&obj->sem_fizzbuzz);
    sem_destroy(&obj->sem_fizz);
    sem_destroy(&obj->sem_buzz);
    sem_destroy(&obj->sem_num);
    free(obj);
    
}

int main() {

    FizzBuzz *data;
    data = fizzBuzzCreate(15);
    pthread_t fizzthread, buzzthread, fizzbuzzthread, numthread;

    pthread_create(&fizzbuzzthread, NULL, (void* (*)(void*))fizzbuzz, (void *)data);
    pthread_create(&buzzthread, NULL, (void* (*)(void*))buzz, (void *)data);
    pthread_create(&fizzthread, NULL, (void* (*)(void*))fizz, (void *)data);
    pthread_create(&numthread, NULL, (void* (*)(void*))number, (void *)data);

    pthread_join(fizzbuzzthread, NULL);
    pthread_join(buzzthread, NULL);
    pthread_join(fizzthread, NULL);
    pthread_join(numthread, NULL);
    return 0;
}