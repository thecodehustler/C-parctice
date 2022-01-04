/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include "public/linked_list.h"

struct ListNode* rotateRight(struct ListNode* head, int k) {
    Node pseudoHead;
    pseudoHead.next = head;
    const int len = length(head);
    printf("%d\n", len);
    if (len < 2) return head;
    k = k % len;
    PNode front = head, back = head;
    for (int i = 0; i < k; i++) {
        front = front->next;
        // back = back->next;
    }
    while (front->next) {
        front = front->next;
        back = back->next;
    }
    front->next = head;
    pseudoHead.next = back->next;
    back->next = 0;
    return pseudoHead.next;
}

int main() {
    int arr[] = {1, 2};
    PNode list = fromArray(arr, 2);
    printf("%d\n", length(list));

    printList(rotateRight(list, 2));
    return 0;
}