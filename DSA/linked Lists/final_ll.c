#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("\nMemory Allocation Failed");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a given node
void insertAfterNode(struct Node* prevNode, int value) {
    if (prevNode == NULL) {
        printf("\nPrevious node cannot be NULL");
        return;
    }
    struct Node* newNode = createNode(value);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf("\nNode with value %d inserted after the given node", value);
}

// Function to insert a node at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("\nNode with value %d inserted at the beginning", value);
}

// Function to insert a node at a specific index
void insertAtIndex(int index, int value) {
    if (index < 0) {
        printf("\nIndex cannot be negative");
        return;
    }
    if (index == 0) {
        insertAtBeginning(value);
        return;
    }
    struct Node* newNode = createNode(value);
    struct Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        if (current == NULL) {
            printf("\nIndex out of bounds");
            return;
        }
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    printf("\nNode with value %d inserted at index %d", value, index);
}

// Function to insert a node at the end
void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    printf("\nNode with value %d inserted at the end", value);
}

// Function to delete a node with a given value
void deleteValue(int value) {
    struct Node* current = head;
    struct Node* prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("\nNode with value %d not found", value);
        return;
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
    printf("\nNode with value %d deleted", value);
}

// Function to delete the node at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("\nList is empty, cannot delete");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);

    printf("\nNode at the beginning deleted");
}

// Function to delete the node after a given node
void deleteAfterNode(struct Node* prevNode) {
    if (prevNode == NULL || prevNode->next == NULL) {
        printf("\nInvalid node, cannot delete");
        return;
    }

    struct Node* temp = prevNode->next;
    prevNode->next = temp->next;
    free(temp);

    printf("\nNode after the given node deleted");
}

// Function to delete the node at the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("\nList is empty, cannot delete");
        return;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        head = NULL;
    } else {
        prev->next = NULL;
    }

    free(current);
    printf("\nNode at the end deleted");
}

// Function to display the linked list
void display() {
    struct Node* current = head;
    printf("\nLinked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, value, index;
    
    do {
        printf("\n1. Insert After Node");
        printf("\n2. Insert At Beginning");
        printf("\n3. Insert At Index");
        printf("\n4. Insert At End");
        printf("\n5. Delete a Value");
        printf("\n6. Delete At Beginning");
        printf("\n7. Delete After Node");
        printf("\n8. Delete At End");
        printf("\n9. Display");
        printf("\n10. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                insertAfterNode(head, value);
                break;
            case 2:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("\nEnter the index to insert: ");
                scanf("%d", &index);
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                insertAtIndex(index, value);
                break;
            case 4:
                printf("\nEnter the value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 5:
                printf("\nEnter the value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 6:
                deleteAtBeginning();
                break;
            case 7:
                printf("\nEnter the value after which to delete: ");
                scanf("%d", &value);
                deleteAfterNode(head);
                break;
            case 8:
                deleteAtEnd();
                break;
            case 9:
                display();
                break;
            case 10:
                printf("\nExiting the program");
                break;
            default:
                printf("\nInvalid Choice");
        }
    } while (choice != 10);

    return 0;
}
