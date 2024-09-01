#include<stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode_t;

struct ListNode* middleNode(struct ListNode* head) {

    ListNode_t *slow, *fast;
    slow = fast = head;
    while(fast && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
   
}

