#include <malloc.h>
#include <stdio.h>
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode* next;
};

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

void recycle(struct ListNode* head, struct ListNode* tail) {
    while (head->next != tail) {
        struct ListNode* fre = head->next;
        head = head->next;
        free(fre);
    }
}

void print(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    putchar('\n');
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode pseudoHead;
    pseudoHead.next = head;
    struct ListNode *slow = &pseudoHead, *fast = &pseudoHead;
    while (slow->next) {
        char flag = 0;  // 是否需要删除文件
        for (fast = slow->next;
             fast->next && (fast->next->val == slow->next->val);
             fast = fast->next) {
            flag = 1;
        }
        if (flag) {
            slow->next = fast->next;

        } else {
            slow->next->next = fast->next;
            slow = slow->next;
        }
    }
    return pseudoHead.next;
}

int main() {
    int arr[] = {1, 1, 1, 2, 3, 3, 3, 4, 4, 4};
    struct ListNode* list = fromArray(arr, sizeof(arr) / sizeof(int));
    print(list);
    print(deleteDuplicates(list));
    return 0;
}