/*
 * Program to remove nth node from end of linked list (Leetcode Q. 19)
 * To be run on leetcode
 * Dushyant Batra,(1910990098), 29/08/2021
 */

//return head of linked list after removing given node.
//params:
//struct ListNode* head: head of linkedlist
//int n: position from end of node which need to be removed
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* first = head;
    struct ListNode* second = head;
    
    for(int i = 0; i < n; i++) {
        first = first->next;
    }
    if(first == NULL) {
        head = head->next;
    }
    else {
        while(first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        struct ListNode* temp = second->next;
        second->next = second->next->next;
        temp->next = NULL;
    }
    return head;
}
