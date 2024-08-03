#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>


//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};
 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode *new, *current, *head;
    int carry = 0;
    int sum;
    head = NULL;

    while (l1 && l2)
    {
        sum = l1->val + l2->val + carry;
        if(sum > 9) {
            carry = 1;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = sum;
        new->next = NULL;

        if(head == NULL) {
            head = new;
        } else {
            current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = new;
        }
        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1)
    {
        sum = l1->val + carry;
        if(sum > 9) {
            carry = 1;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = sum;
        new->next = NULL;

        if(head == NULL) {
            head = new;
        } else {
            current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = new;
        }
        l1 = l1->next;
    }

    while (l2)
    {
        sum = l2->val + carry;
        if(sum > 9) {
            carry = 1;
            sum = sum % 10;
        } else {
            carry = 0;
        }
        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = sum;
        new->next = NULL;

        if(head == NULL) {
            head = new;
        } else {
            current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = new;
        }
        l2 = l2->next;
    }

    if(carry) {

        new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->val = carry;
        new->next = NULL;

        if(head == NULL) {
            head = new;
        } else {
            current = head;
            while(current->next != NULL) {
                current = current->next;
            }
            current->next = new;
        }

    }

    return head;
       
}

int main() {
    return 0;
}