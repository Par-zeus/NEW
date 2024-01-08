#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to display the linked list
void display(struct Node *head) {
    struct Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Function to add a node at the beginning
void addAtBeginning(struct Node **head, int value) {
    struct Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end
void addAtEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

// Function to add a node after a specific value
void addAfterValue(struct Node *head, int afterValue, int newValue) {
    struct Node *current = head;

    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list\n", afterValue);
        return;
    }

    struct Node *newNode = createNode(newValue);
    newNode->next = current->next;
    current->next = newNode;
}

// Function to add a node before a specific value
void addBeforeValue(struct Node **head, int beforeValue, int newValue) {
    struct Node *newNode = createNode(newValue);
    struct Node *current = *head;
    struct Node *prev = NULL;

    if (current != NULL && current->data == beforeValue) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (current != NULL && current->data != beforeValue) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list\n", beforeValue);
        return;
    }

    newNode->next = current;
    prev->next = newNode;
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from beginning\n");
        return;
    }

    struct Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete from end\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current->next != NULL) {
        prev = current;
        current = current->next;
    }

    free(current);
    prev->next = NULL;
}

// Function to delete a node of a specific value
void deleteNodeWithValue(struct Node **head, int value) {
    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL && current->data != value) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    if (prev == NULL) {
        // Node to be deleted is the first node
        *head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Function to delete a node after a specific value
void deleteAfterGivenValue(struct Node *head, int afterValue) {
    struct Node *current = head;

    while (current != NULL && current->data != afterValue) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("Node not found or no node after the value %d\n", afterValue);
        return;
    }

    struct Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Function to delete a node before a specific value
void deleteBeforeGivenValue(struct Node **head, int beforeValue) {
    struct Node *current = *head;
    struct Node *prev = NULL;
    struct Node *prevPrev = NULL;

    while (current != NULL && current->data != beforeValue) {
        prevPrev = prev;
        prev = current;
        current = current->next;
    }

    if (prevPrev == NULL || prev == NULL) {
        printf("Node not found or no node before the value %d\n", beforeValue);
        return;
    }

    free(prev);
    prevPrev->next = current;
}

// Function to delete the whole list
void deleteWholeList(struct Node **head) {
    struct Node *current = *head;
    struct Node *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    *head = NULL;
}

int main() {
    struct Node *head = NULL;
    int choice, value, newValue, afterValue, beforeValue;

    do {
        printf("\n1. Create List");
        printf("\n2. Display List");
        printf("\n3. Add Node at Beginning");
        printf("\n4. Add Node at End");
        printf("\n5. Add Node After a Value");
        printf("\n6. Add Node Before a Value");
        printf("\n7. Delete Node from Beginning");
        printf("\n8. Delete Node from End");
        printf("\n9. Delete a Node of Value");
        printf("\n10. Delete After a Given Value");
        printf("\n11. Delete Before a Given Value");
        printf("\n12. Delete Whole List");
        printf("\n0. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            // Create List
            printf("\nEnter the value for the first node: ");
            scanf("%d", &value);
            head = createNode(value);
            break;

        case 2:
            // Display List
            display(head);
            break;

        case 3:
            // Add Node at Beginning
            printf("\nEnter the value to add at the beginning: ");
            scanf("%d", &value);
            addAtBeginning(&head, value);
            break;

        case 4:
            // Add Node at End
            printf("\nEnter the value to add at the end: ");
            scanf("%d", &value);
            addAtEnd(&head, value);
            break;

        case 5:
            // Add Node After a Value
            printf("\nEnter the value after which to add: ");
            scanf("%d", &afterValue);
            printf("\nEnter the new value to insert: ");
            scanf("%d", &newValue);
            addAfterValue(head, afterValue, newValue);
            break;

        case 6:
            // Add Node Before a Value
            printf("\nEnter the value before which to add: ");
            scanf("%d", &beforeValue);
            printf("\nEnter the new value to insert: ");
            scanf("%d", &newValue);
            addBeforeValue(&head, beforeValue, newValue);
            break;

        case 7:
            // Delete Node from Beginning
            deleteFromBeginning(&head);
            break;

        case 8:
            // Delete Node from End
            deleteFromEnd(&head);
            break;

        case 9:
            // Delete a Node of Value
            printf("\nEnter the value to delete: ");
            scanf("%d", &value);
            deleteNodeWithValue(&head, value);
            break;

        case 10:
            // Delete After a Given Value
            printf("\nEnter the value after which to delete: ");
            scanf("%d", &afterValue);
            deleteAfterGivenValue(head, afterValue);
            break;

        case 11:
            // Delete Before a Given Value
            printf("\nEnter the value before which to delete: ");
            scanf("%d", &beforeValue);
            deleteBeforeGivenValue(&head, beforeValue);
            break;

        case 12:
            // Delete Whole List
            deleteWholeList(&head);
            printf("List deleted\n");
            break;

        case 0:
            break;

        default:
            printf("\nInvalid choice. Please enter a valid option.");
        }

    } while (choice != 0);

    // Freeing memory
    // freeList(head);

    return 0;
}

