#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    struct Node* newNode = createNode(value);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d enqueued to the queue.\n", value);
}

// Function to dequeue an element
void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is EMPTY. Cannot dequeue.\n");
        return;
    }
    struct Node* temp = queue->front;
    int value = temp->data;
    queue->front = temp->next;
    free(temp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("%d dequeued from the queue.\n", value);
}

// Function to peek the front element of the queue
void peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is EMPTY.\n");
    } else {
        printf("The front element is: %d\n", queue->front->data);
    }
}

// Function to display the elements of the queue
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is EMPTY.\n");
    } else {
        struct Node* temp = queue->front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    struct Queue* queue = initializeQueue();
    int choice, value;

    do {
        printf("\nEnter 1 to enqueue");
        printf("\nEnter 2 to dequeue");
        printf("\nEnter 3 to peek");
        printf("\nEnter 4 to display");
        printf("\nEnter 5 to EXIT");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                peek(queue);
                break;
            case 4:
                display(queue);
                break;
        }
    } while (choice != 5);

    return 0;
}
