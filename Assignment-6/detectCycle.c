/*
 * Program to detect cycle in the linkedlist(Leetcode Q. 142)
 * To be run on leetcode
 * Dushyant Batra,(1910990098), 29/08/2021
 */

//return node from where cycle in linked list begin.
//params:
//struct ListNode* head: head of linkedlist
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* current = head;
    int flag = 0;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if(fast ==  slow) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
    
}
