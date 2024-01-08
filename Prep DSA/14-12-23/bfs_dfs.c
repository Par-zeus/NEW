#include <stdio.h>
#define MAX 10
int queue[20], top=-1,front = -1, rear = -1, adjacencyMatrix[20][20], visited[20], stack[20];

// Function prototypes
int dequeue();
void enqueue(int item);
void bfs(int start, int vertices);
void dfs(int start, int vertices);
void push(int item);
int pop();

int main() {
    int vertices, i, start, choice, j;
    char continueChoice;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Inputting the adjacency matrix
    for (i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            printf("Is there an edge between vertex %d and %d? (1/0): ", i, j);
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    // Displaying the adjacency matrix
    printf("\nThe Adjacency Matrix is: \n");
    for (i = 1; i <= vertices; i++) {
        for (j = 1; j <= vertices; j++) {
            printf(" %d", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }

    do {
        // Initializing visited array for each traversal
        for (i = 1; i <= vertices; i++)
            visited[i] = 0;

        // Menu for BFS and DFS
        printf("\nMenu");
        printf("\n1. Breadth-First Search (BFS)");
        printf("\n2. Depth-First Search (DFS)");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Inputting the source vertex
        printf("Enter the source vertex: ");
        scanf("%d", &start);

        // Performing the selected traversal
        switch (choice) {
            case 1:
                bfs(start, vertices);
                break;
            case 2:
                dfs(start, vertices);
                break;
        }

        // Asking the user if they want to continue
        printf("\nDo you want to continue (y/n)? ");
        scanf(" %c", &continueChoice);

    } while (continueChoice == 'y' || continueChoice == 'Y');

    return 0;
}

// Function to perform Breadth-First Search (BFS)
void bfs(int start, int vertices) {
    int current;
    enqueue(start);
    visited[start] = 1;

    printf("\nBFS Traversal starting from vertex %d: ", start);

    while ((current = dequeue()) != 0) {
        printf("%d ", current);

        // Enqueue adjacent vertices if not visited
        for (int i = 1; i <= vertices; i++) {
            if (adjacencyMatrix[current][i] != 0 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Function to perform Depth-First Search (DFS)
void dfs(int start, int vertices) {
    int current;
    push(start);
    visited[start] = 1;

    printf("\nDFS Traversal starting from vertex %d: ", start);

    while ((current = pop()) != 0) {
        printf("%d ", current);

        // Push adjacent vertices onto the stack if not visited
        for (int i = 1; i <= vertices; i++) {
            if (adjacencyMatrix[current][i] != 0 && !visited[i]) {
                push(i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Function to enqueue an element into the queue
void enqueue(int item) {
    if (rear == MAX - 1)
        printf("Queue full..");
    else {
        if (front == -1)
            front = 0;
        queue[++rear] = item;
    }
}


// Function to dequeue an element from the queue
int dequeue() {
    if (front > rear || front == -1)
        return 0;
    else
        return queue[front++];
}

// Function to push an element onto the stack
void push(int item) {
    if (top == MAX)
        printf("Stack overflow...");
    else
        stack[++top] = item;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1)
        return 0;
    else
        return stack[top--];
}
