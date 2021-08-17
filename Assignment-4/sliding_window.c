/*
 * Program to return max sliding window.
 * Output- To be run on Leetcode Q.239
 * Dushyant Batra,(1910990098),16/08/2021
 * Assignment - 4(Stacks and Queues)
 */

//structure to implement Dequeue
typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

//Global Variables
Node* head = NULL;
Node* tail = NULL;

//add val to dequeue from last.
//params:
//int val: val to be added
void addLast(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    node->prev = NULL;
    
    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }
    
    tail->next = node;
    node->prev = tail;
    tail = node;
}

//add val to dequeue from start.
//params:
//int val: val to be added
void addFirst(int val) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = val;
    node->next = NULL;
    node->prev = NULL;
    
    if(head == NULL && tail == NULL) {
        head = tail = node;
        return;
    }
    
    head->prev = node;
    node->next = head;
    head = node;
}

//remove the element from last.
int removeLast() {
    if(head == NULL && tail == NULL) {
        return -1;
    }
    
    int val = tail->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }
    
    tail = tail->prev;
    tail->next = NULL;
    
    return val;
}

//remove the element from start.
int removeFirst() {
    if(head == NULL && tail == NULL) {
        return -1;
    }
    
    int val = head->value;
    if(head == tail) {
        head = tail = NULL;
        return val;
    }
    
    head = head->next;
    head->prev = NULL;
    
    return val;
}

//get the element present at last.
int getLast() {
    if(head == NULL && tail == NULL) {
        return -1;
    }
    
    int val = tail->value;    
    return val;
}

//get the element present at end.
int getFirst() {
    if(head == NULL && tail == NULL) {
        return -1;
    }
    
    int val = head->value;    
    return val;
}

//check whether queue is empty or not
//return int:1 if dequeue is empty else return 0.
int isEmpty() {
    if(head == NULL && tail == NULL) {
        return 1;
    }
    
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
        
    *returnSize = numsSize - k + 1;
    int* res = (int*) malloc(*returnSize * sizeof(int));
    int ind = 0;
        
    for(int i = 0; i < numsSize; i++) {
        if(isEmpty() == 0 && getFirst() == i - k)
            removeFirst();
            
        while(isEmpty() == 0 && nums[getLast()] < nums[i])
            removeLast();
            
        addLast(i);
        if(i >= k - 1)
            res[ind++] = nums[getFirst()];
    }
        
    head = NULL;
    tail = NULL;
    return res;
}
