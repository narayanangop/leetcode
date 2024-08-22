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
 
bool hasCycle(struct ListNode *head) {

    struct ListNode *slow, *fast;
    slow = fast = head;

    while(fast && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            return true;
        }
    }

    return false;
    
}