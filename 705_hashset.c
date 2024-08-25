
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

typedef struct {

    char *data;
    
} MyHashSet;


MyHashSet* myHashSetCreate() {

    MyHashSet *obj = (MyHashSet *)calloc(1, sizeof(MyHashSet));
    obj->data = (char *)calloc((1000001/sizeof(char)), sizeof(char));
    return obj;
    
}

void myHashSetAdd(MyHashSet* obj, int key) {

    int index = key / sizeof(char);
    int offset = key % sizeof(char);

    obj->data[index] |= (1 << offset);
    
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = key / sizeof(char);
    int offset = key % sizeof(char);

    obj->data[index] &= ~(1 << offset);
}

bool myHashSetContains(MyHashSet* obj, int key) {
    int index = key / sizeof(char);
    int offset = key % sizeof(char);

    return((obj->data[index] & (1 << offset)) != 0);
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/