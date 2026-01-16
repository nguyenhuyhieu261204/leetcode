#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

#define MAX_SIZE 200000

typedef struct Node {
    int value;
    int index;
    struct Node* next;
} Node;

typedef struct {
    int* arr;
    int cur;
    Node** hashTable;
} RandomizedSet;

int hash(int key) {
    return (key & 0x7FFFFFFF) % MAX_SIZE;
}

RandomizedSet* randomizedSetCreate() {
    RandomizedSet* rs = malloc(sizeof(RandomizedSet));
    rs->cur = 0;
    rs->arr = malloc(sizeof(int) * MAX_SIZE);
    rs->hashTable = malloc(sizeof(Node*) * MAX_SIZE);
    memset(rs->hashTable, 0, MAX_SIZE * sizeof(Node*));
    return rs;
}

bool randomizedSetInsert(RandomizedSet* obj, int val) {
    int key = hash(val);
    Node* cur = obj->hashTable[key];
    while (cur) {
        if (cur->value == val) return false;
        cur = cur->next;
    }
    Node* newNode = malloc(sizeof(Node));
    newNode->value = val;
    newNode->index = obj->cur;
    newNode->next = obj->hashTable[key];
    obj->hashTable[key] = newNode;
    obj->arr[obj->cur++] = val;
    return true;
}

bool randomizedSetRemove(RandomizedSet* obj, int val) {
    if (obj->cur == 0) return false;
    int key = hash(val);
    Node* cur = obj->hashTable[key];
    Node* prev = NULL;
    while (cur && cur->value != val) {
        prev = cur;
        cur = cur->next;
    }
    if (!cur) return false;
    int removeIndex = cur->index;
    int lastVal = obj->arr[obj->cur-1];
    if (prev) {
        prev->next = cur->next;
    } else {
        obj->hashTable[key] = cur->next;
    }
    obj->arr[removeIndex] = lastVal;
    int lastKey = hash(lastVal);
    Node* upd = obj->hashTable[lastKey];
    while (upd) {
        if (upd->value == lastVal) {
            upd->index = removeIndex;
            break;
        } 
        upd = upd->next;
    }
    free(cur);
    obj->cur --;
    return true;
}

int randomizedSetGetRandom(RandomizedSet* obj) {
    if (obj->cur == 0) return -1;
    int randIndex = rand() % obj->cur;
    return obj->arr[randIndex];
}

void randomizedSetFree(RandomizedSet* obj) {
    free(obj->arr);
    free(obj->hashTable);
    free(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/