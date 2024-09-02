// Add items at the end of the buffer
// read items in the beginning of the buffer
// if the buffer is full. overwrite the items
// Do we need thread safety?

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<pthread.h>

typedef struct circ_buf {
    int *data;
    int capacity;
    int head;
    int tail;
    int cur_size;
    pthread_mutex_t mutex;
} circ_buf_t;

// Initialize the buffer to hold x elements.
circ_buf_t * circular_buffer_int(int capacity);

// returns 0 on success. -1 on failure.
int circular_buffer_add(circ_buf_t *obj, int data);

// returns 0 on success. -1 on failure(buffer is empty).
int circular_buffer_remove(circ_buf_t *obj, int *data);

// destroy the buffer.
void circular_buffer_destroy(circ_buf_t *obj);


circ_buf_t * circular_buffer_int(int capacity) {

    /* Allocate memeory */
    circ_buf_t *obj = (circ_buf_t *)malloc(sizeof(circ_buf_t));
    if(!obj)
        return NULL;

    obj->data = (int *)malloc(sizeof(int) * capacity);
    if(obj->data == NULL) {
        free(obj);
        return NULL;
    }

    obj->head = 0;
    obj->tail = 0;
    obj->capacity = capacity;
    obj->cur_size = 0;
    pthread_mutex_init(&obj->mutex, NULL);

    return obj;
    
}

int circular_buffer_add(circ_buf_t *obj, int data) {

    if (obj == NULL)
        return -1;

    pthread_mutex_lock(&obj->mutex);

    /* if the buffer is full increment head. mod with capacity will help 
       rollover */
    if (obj->cur_size == obj->capacity) {
        obj->head = (obj->head + 1) % obj->capacity;
    } else {
        obj->cur_size++;
    }

    /* Always add data to the head and remove from the tail */
    obj->data[obj->tail] = data;
    obj->tail = (obj->tail + 1) % obj->capacity;


    pthread_mutex_unlock(&obj->mutex);

    return 0;
}

int circular_buffer_remove(circ_buf_t *obj, int *data) {

    if (obj == NULL)
        return -1;

    /* return error if there is nothing to read */
    if (obj->cur_size == 0)
        return -1;
    pthread_mutex_lock(&obj->mutex);
    *data = obj->data[obj->head];
    obj->head = (obj->head + 1) % obj->capacity;
    obj->cur_size--;
    pthread_mutex_unlock(&obj->mutex);

    return 0;

}

void circular_buffer_destroy(circ_buf_t *obj) {

    pthread_mutex_lock(&obj->mutex);
    free(obj->data);
    free(obj);
    pthread_mutex_unlock(&obj->mutex);

}

int main() {
    circ_buf_t *buf;
    int ret;
    int data;
    int i;
    buf = circular_buffer_int(10);

    for(i=0; i<15; i++) {
        ret = circular_buffer_add(buf, i);
    }

     for(i=0; i<12; i++) {
        ret = circular_buffer_remove(buf, &data);
        if(ret == 0) {
            printf("%d, ", data);
        } else {
            printf("err ");
        }
    }
    circular_buffer_destroy(buf);
    


    return 0;
}
