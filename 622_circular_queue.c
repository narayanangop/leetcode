#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

typedef struct {
    int *data;
    int rear;
    int front;
    int size;
    int capacity;
    
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {

    MyCircularQueue *obj;

    obj = (MyCircularQueue *)malloc(sizeof(MyCircularQueue));
    if(!obj) {
        return NULL;
    }

    obj->data = (int *)malloc(sizeof(int) * k);
    if(!obj->data) {
        free(obj);
        return NULL;
    }

    obj->capacity = k;
    obj->size = 0;
    obj->front = 0;
    obj->rear = obj->capacity - 1;

    return obj;  
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    
    if(obj->size == obj->capacity) {
        return false;
    }

    obj->rear = (obj->rear + 1) % obj->capacity;
    obj->data[obj->rear] = value;
    obj->size++;

    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {

    if(obj->size == 0)
        return false;

    obj->front = (obj->front + 1) % obj->capacity;
    obj->size--;

    return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {

    if(obj->size == 0)
        return -1;

    return(obj->data[obj->front]);
    
}

int myCircularQueueRear(MyCircularQueue* obj) {

    if(obj->size == 0)
        return -1;
    
    return(obj->data[obj->rear]);

}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {

    return((obj->size == 0) ? true: false);
   
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {

    return((obj->size == obj->capacity) ? true: false);

}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj->data);
    free(obj);
}

int main() {
    return 0;
}