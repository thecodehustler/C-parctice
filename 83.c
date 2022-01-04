#include <malloc.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

typedef struct ListNode Node, *PNode;

struct ListNode* deleteDuplicates(struct ListNode* head) {
    PNode slow = head, fast = head;
    while (fast) {
        for (fast = slow; fast && fast->val == slow->val; fast = fast->next) {
            ;
        }
        slow->next = fast;
        slow = slow->next;
    }
    return head;
}

void print(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    putchar('\n');
}

struct ListNode* fromArray(int arr[], int size) {
    struct ListNode pseudoHead, *curr = &pseudoHead;
    for (int i = 0; i < size; i++) {
        curr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        curr->next->val = arr[i];
        curr->next->next = 0;
        curr = curr->next;
    }
    return pseudoHead.next;
}

int main() {
    int arr[] = {0, 0, 0, 0, 0, 0, 0, 0};
    PNode list = fromArray(arr, sizeof(arr) / sizeof(int));
    print(deleteDuplicates(list));
    return 0;
}