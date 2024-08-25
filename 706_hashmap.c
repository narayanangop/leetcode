
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

#define HASHMAP_SIZE (1000001)


typedef struct {
    int *data;
} MyHashMap;


MyHashMap* myHashMapCreate() {

    MyHashMap *obj;
    obj = (MyHashMap *)malloc(sizeof(MyHashMap));
    obj->data = (int *)malloc(sizeof(int) * HASHMAP_SIZE);
    for(int i=0; i<HASHMAP_SIZE; i++) {
        obj->data[i] = INT_MAX;
    }

    return obj;
    
}

void myHashMapPut(MyHashMap* obj, int key, int value) {

    obj->data[key] = value;
    
}

int myHashMapGet(MyHashMap* obj, int key) {

    if(obj->data[key] == INT_MAX) {
        return -1;
    }

    return(obj->data[key]);
    
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->data[key] = INT_MAX;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/