/*
 * Program to merge two sorted lists (Leetcode Q. 21)
 * To be run on leetcode
 * Dushyant Batra,(1910990098), 29/08/2021
 */

//return head of merged list.
//params:
//struct ListNode* l1: head of linkedlist1
//struct ListNode* l2: head of linkedlist2
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL && l2 == NULL) {
        return NULL;
    }
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));

    struct ListNode* current = head;
    while(l1 != NULL && l2 != NULL) {
        if(l1->val < l2->val) {
            current->next = l1;
            l1 = l1->next;
            current = current->next;
        }
        else {
            current->next = l2;
            l2 = l2->next;
            current = current->next;
        }
    }
    while(l1 != NULL) {
        current->next = l1;
        l1 = l1->next;
        current = current->next;
    }
    while(l2 != NULL) {
        current->next = l2;
        l2 = l2->next;
        current = current->next;
    }
    head = head->next;
    return head;
}
