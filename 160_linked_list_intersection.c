#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {

    struct ListNode *curA, *curB;
    int lenA, lenB;

    curA = headA;
    curB = headB;

    lenA = lenB = 0;

    /* find the length of the lists */
    while(curA) {
        curA = curA->next;
        lenA++;
    }

    while(curB) {
        curB = curB->next;
        lenB++;
    }
    curA = headA;
    curB = headB;
    /* move the longer list forward to make it equal to the shorter list */

    while(curA && (lenA > lenB)) {
        curA = curA->next;
        lenA--;
    }

    while(curB && (lenB > lenA)) {
        curB = curB->next;
        lenB--;
    }

    while(curA && curB) {
        if(curA == curB) {
            return curA;
        }
        curA = curA->next;
        curB = curB->next;
    }

    return NULL;

}
