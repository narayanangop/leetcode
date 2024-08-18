#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>
#include<limits.h>

/**
 * Definition for singly-linked list.
 */
 struct ListNode {
     int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {

    struct ListNode *prev, *cur, *tmp;
    prev = NULL;
    cur = head;

    while(cur) {
        tmp = cur->next;
        cur->next = prev;
        prev=cur;
        cur=tmp;
    }
    return prev;
    
}