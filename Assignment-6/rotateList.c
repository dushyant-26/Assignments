/*
 * Program to rotate a list to right by k places (Leetcode Q. 61)
 * To be run on leetcode
 * Dushyant Batra,(1910990098), 29/08/2021
 */


//return head of rotated list
//Params:
//struct ListNode* head: head of linkedlist
//int k: rotate by k places 
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(head == NULL) {
        return NULL;
    }
    // if(head->next == NULL) {
    //     return head;
    // }
    struct ListNode* current = head;
    int count = 0;
    
    while(current != NULL) {
        count++;
        current = current->next;
    }
    
    k = k % count;
    if(k == 0) {
        return head;
    }
    struct ListNode* first = head;
    struct ListNode* second = head;
    for(int i = 0 ; i < k; i++) {
        first = first->next;
    }
    
    while(first->next != NULL) {
        first = first->next;
        second = second->next;
    }
    first->next = head;
    head = second->next;
    second->next = NULL;
    
    
    return head;
}
