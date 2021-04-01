#include <malloc.h>
#include <stdio.h>

struct ListNode {
  int val;
  struct ListNode* next;
};

typedef struct ListNode Node, *PNode;


void printList(struct ListNode* head) {
  while (head) {
    printf("%d ", head->val);
    head = head->next;
  }
  putchar('\n');
}

struct ListNode* fromArray(int arr[], int size) {
  // const int size = sizeof(arr) / sizeof(int);
  struct ListNode pseudoHead, *curr = &pseudoHead;
  for (int i = 0; i < size; i++) {
    curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    curr->next->val = arr[i];
    curr->next->next = 0;
    curr = curr->next;
  }
  return pseudoHead.next;
}

int length(struct ListNode* head) {
  Node* curr = head;
  int len = 0;
  while (curr) {
    len ++;
    curr = curr->next;
  }
  return len;
}