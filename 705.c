#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

#define BUCKET_COUNT 1000

typedef struct element {
    int data;
    struct element* next;
} Element;

typedef struct {
    Element* buckets;
} MyHashSet;

int hashing(int key) { return key % BUCKET_COUNT; }

MyHashSet* myHashSetCreate() {
    MyHashSet* ptr = (MyHashSet*)malloc(sizeof(MyHashSet));
    ptr->buckets = calloc(BUCKET_COUNT, sizeof(Element));
    for (int i = 0; i < BUCKET_COUNT; i++) {
        (ptr->buckets + i)->next = 0;
        (ptr->buckets + i)->data = 0;
    }
    return ptr;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    const int bucket = hashing(key);
    Element* curr = obj->buckets + bucket;
    while (curr->next) {
        if (curr->next->data == key) {
            return;
        } else if (curr->next->data > key) {
            break;
        }
        curr = curr->next;
    }

    printf("Insert element %d, ", key);
    if (curr) printf("after %d.\n", curr->data);
    Element* newElement = (Element*)malloc(sizeof(Element));
    newElement->data = key;
    newElement->next = curr->next;
    curr->next = newElement;

    return;
}

void myHashSetRemove(MyHashSet* obj, int key) {
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
bool myHashSetContains(MyHashSet* obj, int key) {
    const int bucket = hashing(key);
    Element* curr = obj->buckets + bucket;

    while (curr->next && curr->next->data <= key) {
        printf("curr->next->data = %d\n", curr->next->data);
        if (curr->next->data == key) {
            return true;
        }
        curr = curr->next;
    }

    return false;
}

void myHashSetFree(MyHashSet* obj) {
    for (int i = 0; i < BUCKET_COUNT; i++) {
        Element* curr =
            (obj->buckets + i)->next;  // 从 next 开始，后续的元素都是通过 malloc 申请得到的。
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
    MyHashSet* set = myHashSetCreate();
    myHashSetAdd(set, 1);
    myHashSetAdd(set, 2);
    printf("%d", myHashSetContains(set, 2));
    myHashSetFree(set);
    return 0;
}