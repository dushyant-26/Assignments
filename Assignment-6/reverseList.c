/*
 * Program to reverse linked list between two given positions (Leetcode Q. 92)
 * To be run on leetcode
 * Dushyant Batra,(1910990098), 29/08/2021
 */

//return head of inversed list.
//params:
//struct ListNode* head: head of linkedlist
//int pos: starting index of linkedlist
//int end:end index of linkedlist upto which list is to be reversed
struct ListNode* inverse(struct ListNode* head,int pos, int end) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    
    while(current != NULL) {
        struct ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        if(pos == end) {
            head->next = current;
            head = prev;
            break;
        }
        pos++;
    }
    return head;
    
    
}

//return head of inversed list.
//params:
//struct ListNode* head: head of linkedlist
//int left: starting index of linkedlist from where list is to be reversed
//int right:end index of linkedlist upto which list is to be reversed
struct ListNode* reverseBetween(struct ListNode* head, int left, int right){
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    int pos = 1;
    
    while(current != NULL && pos != left) {
        prev = current;
        current = current->next;
        pos++;
    }
    if(left != 1){
        prev->next = NULL;
    }
    struct ListNode* inversed= inverse(current,left, right);
    
    if(prev != NULL) {
        prev->next = inversed;
    }
    else {
        return inversed;
    }
    return head;
    
}
