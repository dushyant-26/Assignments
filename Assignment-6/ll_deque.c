/*
 * Program to implement a deque using LinkedList
 * Compilation- gcc -o ll_deque ll_deque.c
 * Execution- ./ll_deque
 * Dushyant Batra,(1910990098), 28/08/2021
 */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//structure of node
typedef struct node {
    int val;
    struct node* next;
    struct node* prev;
} node;

node* head;
node* tail;

//add element to deque from beginning
//params:
//int val:num to be added
void addFirst(int val) {
    node* element = (node*)malloc(sizeof(node));
    element->val = val;
    
    if(head == NULL) {
        head = tail = element;
	return;
    }
    element->next = head;
    head->prev = element;
    head = element;
}

//add element to deque from end
//params:
//int val:num to be added
void addLast(int val) {
    node* element = (node*)malloc(sizeof(node));
    element->val = val;

    if(head == NULL) {
        head = tail = element;
        return;
    }
    tail->next = element;
    element->prev = tail;
    tail = element;
}

//remove element from beginning
int removeFirst() {
    if(head == NULL) {
	printf("Empty Deque\n");
        return INT_MIN;
    }
    node* temp = head;
    head = head->next;
    if(head == NULL) {
        tail = NULL;
    }
    else {
        head->prev = NULL;
    }
    temp->next = NULL;
    int val = temp->val;
    free(temp);
    return val;

}

//remove element from end
int removeLast() {
    if(head == NULL) {
        printf("Empty Deque\n");
        return INT_MIN;
    }
    node* temp = tail;
    tail = tail->prev;
    if(tail == NULL) {
        head = NULL;
    }
    else {
        tail->next = NULL;
    }
    temp->prev = NULL;
    int val = temp->val;
    free(temp);
    return val;

}

//return the val of element present at start of linkedlist
int peekFirst() {
    if(head == NULL) {
        printf("Empty Deque\n");
	return INT_MIN;
    }
    return head->val;
}

//return the val of element present at end of linkedlist
int peekLast() {
    if(head == NULL) {
        printf("Empty Deque\n");
        return INT_MIN;
    }
    return tail->val;
}

//check whether deque is empty or not
int isEmpty() {
    return (head == NULL); 
}

//check whether given num is present in deque or not
//params:
//int val:num to be check in deque
int check(int val) {
    node* current = head;
    while(current != NULL) {
        if(current->val == val) {
	    return 1;
	}
	current = current->next;
    }
    return 0;
}

//print deque
void print() {
    node* current = head;
    while(current != NULL) {
        printf("%d ",current->val);
	current = current->next;
    }
    printf("\n");
}

int main(void) {

    while(1) {
        int choice = 0;
        int num = 0;

        printf("\nWhich operation do you want to do?\n");
        printf("1. addFirst operation\n");
	printf("2. addLast operation\n");
        printf("3. removeFirst operation\n");
	printf("4. removeLast operation\n");
        printf("5. peekFirst operation\n");
	printf("6. peekLast operation\n");
        printf("7. Check whether Deque is Empty or not\n");
	printf("8. Print the elements present in Deque\n");
	printf("9. Check whether given element present in deque\n");
        printf("10. Exit the Program\n");

        scanf("\n%d",&choice);

	int val;
        switch(choice) {
            case 1:
                printf("\nEnter the number to add:\n");
                scanf("%d",&num);
                addFirst(num);
                break;
	    case 2:
		printf("\nEnter the number to add:\n");
                scanf("%d",&num);
                addLast(num);
		break;
            case 3:
		val = removeFirst();
		if(val != INT_MIN) {
                    printf("\nThe number removed from start of deque is %d\n", val);
		}
                break;
	    case 4:
		val = removeLast();
                if(val != INT_MIN) {
                    printf("\nThe number removed from end of deque is %d\n", val);
                }
                break;
            case 5:
		val = peekFirst();
		if(val != INT_MIN) {
                    printf("\nThe number present on start of Deque is %d\n", val);
		}
                break;
	    case 6:
                val = peekLast();
                if(val != INT_MIN) {
                    printf("\nThe number present on end of Deque is %d\n", val);
                }
                break;

            case 7:
                if(isEmpty()) {
                    printf("\nYes, the deque is empty\n");
                }
                else {
                    printf("\nNo, the deque is not empty\n");
                }
                break;
	    case 8:
		print();
		break;
	    case 9:
	        printf("\nEnter the number to check:\n");
                scanf("%d",&num);
                if(check(num) == 1) {
		    printf("Yes, the given element is present in deque\n");
		}
		else {
		    printf("No, the given element is not present in the deque\n");
		}
		break;
            case 10:
                exit(1);
            default:
                printf("\nInvalid operation\n");
        }
    }
    return 0;
}
