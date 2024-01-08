#include <stdio.h>
#include <conio.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int vertex) {
    if (rear == MAX - 1) {
        printf("Queue is FULL\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1) {
        printf("Queue is EMPTY\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

int isEmpty() {
    return front == -1;
}

void breadthFirstSearch(int adjMatrix[MAX][MAX], int vertices, int startVertex) {
    int visited[MAX] = {0};
    int currentVertex;
    
    printf("Breadth-First Search starting from node %d: ", startVertex);
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    enqueue(startVertex);

    while (!isEmpty()) {
        currentVertex = dequeue();

// If a vertex is a neighbor (i.e., adjMatrix[currentVertex][i] == 1)
//  and it has not been visited (!visited[i]),
//  it is marked as visited, printed as part of the BFS traversal, 
// and enqueued for further exploration.
        for (int i = 0; i < vertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int vertices;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    int adjMatrix[MAX][MAX];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    breadthFirstSearch(adjMatrix, vertices, startVertex);

    getch();
    return 0;
}
