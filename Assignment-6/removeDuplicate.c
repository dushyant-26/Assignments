/*
 * Program to remove duplicate nodes from linked list (Leetcode Q. 82)
 * To be run on leetcode
 * Dushyant Batra,(1910990098), 29/08/2021
 */

//return head of linkedlist with no duplicate node.
//params:
//struct ListNode* head: head of linkedlist
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode* head1 = (struct ListNode*) (malloc(sizeof(struct ListNode)));
    struct ListNode* tail1 = head1;
    struct ListNode* current = head;
    
    while(current != NULL && current->next != NULL) {
        if(current->val == current->next->val) {
            while(current->next != NULL && current->next->val == current->val) {
                current = current->next;
            }
        }
        else {
            tail1->next = current;
            tail1 = current;
        }
        current = current->next; 
    }
    
    tail1->next = current;
    return head1->next;
}
