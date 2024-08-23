/**
 * Definition for singly-linked list.
 */ 

    struct ListNode {
      int val;
      struct ListNode *next;
  };
 

struct ListNode* plusOne(struct ListNode* head){

    struct ListNode *current, *notnine;
    
    struct ListNode *sentinel = (struct ListNode *)malloc(sizeof(struct ListNode));
    sentinel->val = 0;
    sentinel->next = head;
    current = sentinel;
    while(current) {
        if(current->val != 9) {
            notnine = current;
        }
        current = current->next;
    }
    current = notnine->next;

    while(current) {
        current->val = 0;
        current = current->next;
    }
    notnine->val++;
    if(sentinel->val == 1) {
        return sentinel;
    }

    return sentinel->next;

}