/*
 * Program to check whether given linked list is palindrome or not(Leetcode Q. 234)
 * To be run on leetcode
 * Dushyant Batra,(1910990098), 29/08/2021
 */

//check whether given linked list is palindrome or not.
//params:
//struct ListNode* head: head of linkedlist
//return bool: true if linked list is palindrome else return false.
bool isPalindrome(struct ListNode* head){
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    if(head == NULL || head->next == NULL) {
        return true;
    }
    
    struct ListNode* prev = NULL;
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
     
    prev->next = NULL;
    prev = NULL;
    struct ListNode* current = slow;
    struct ListNode* next;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    current = head;
    while(current != NULL) {
        if(current->val != prev->val) {
            return false;
        }
        current = current->next;
        prev = prev->next;
    }
    return true; 
}
