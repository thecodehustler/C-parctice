#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#define BUCKET_COUNT 1000

typedef struct element {
    int data;
    int val;
    struct element* next;
} Element;

typedef struct {
    Element* buckets;
} MyHashMap;

int hashing(int key) { return key % BUCKET_COUNT; }

MyHashMap* myHashMapCreate() {
    MyHashMap* ptr = (MyHashMap*)malloc(sizeof(MyHashMap));
    ptr->buckets = calloc(BUCKET_COUNT, sizeof(Element));
    /*   for (int i = 0; i < BUCKET_COUNT; i++) {
        (ptr->buckets + i) -> next = 0;
        (ptr->buckets + i) -> data = 0;
      } */
    return ptr;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    const int bucket = hashing(key);
    Element* curr = obj->buckets + bucket;
    while (curr->next) {
        if (curr->next->data == key) {
            curr->next->val = value;
            return;
        } else if (curr->next->data > key) {
            break;
        }
        curr = curr->next;
    }

    // printf("Insert element %d, ", key);
    // if (curr) printf("after %d.\n", curr->data);
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->data = key;
    newElement->val = value;
    newElement->next = curr->next;
    curr->next = newElement;

    return;
}

void myHashMapRemove(MyHashMap* obj, int key) {
    const int bucket = hashing(key);
    Element* curr = obj->buckets + bucket;

    while (curr->next && curr->next->data <= key) {
        if (curr->next->data == key) {
            Element* tobeDeleted = curr->next;
            curr->next = curr->next->next;
            free(tobeDeleted);
            return;
        }
        curr = curr->next;
    }

    return;
}

/** Returns true if this set contains the specified element */
int myHashMapGet(MyHashMap* obj, int key) {
    const int bucket = hashing(key);
    Element* curr = obj->buckets + bucket;

    while (curr->next && curr->next->data <= key) {
        // printf("curr->next->data = %d\n", curr->next->data);
        if (curr->next->data == key) {
            return curr->next->val;
        }
        curr = curr->next;
    }

    return -1;
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        Element* curr =
            (obj->buckets + i)
                ->next;  // 从 next 开始，后续的元素都是通过 malloc 申请得到的。
        while (curr) {
            Element* tobeDeleted = curr;
            curr = curr->next;
            free(tobeDeleted);
        }
    }
    free(obj->buckets);
    free(obj);
}

int main() {
    MyHashMap* set = myHashMapCreate();
    myHashMapAdd(set, 1);
    myHashMapAdd(set, 2);
    printf("%d", myHashMapContains(set, 2));
    myHashMapFree(set);
    return 0;
}