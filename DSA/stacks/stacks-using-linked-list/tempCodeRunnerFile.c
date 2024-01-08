#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory Overflow");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("\n%d pushed onto the stack", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("\nStack Underflow");
        return;
    }
    struct Node* temp = top;
    int value = temp->data;
    top = temp->next;
    free(temp);
    printf("\nThe popped element is: %d", value);
}

// Function to peek the top element of the stack
void peek() {
    if (top == NULL) {
        printf("\nStack is EMPTY");
        return;
    }
    printf("\nThe peek element is: %d", top->data);
}

// Function to display all elements in the stack
void display() {
    if (top == NULL) {
        printf("\nStack is EMPTY");
        return;
    }
    printf("\nStack elements:");
    struct Node* temp = top;
    while (temp != NULL) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice, value;

    do {
        printf("\n Enter 1 for push");
        printf("\n Enter 2 for pop");
        printf("\n Enter 3 for peek");
        printf("\n Enter 4 for display all elements");
        printf("\n Enter 5 for EXIT");

        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter the value to be inserted into the stack:");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
        }
    } while (choice != 5);

    return 0;
}
