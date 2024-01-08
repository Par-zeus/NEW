#include <stdio.h>
#include <conio.h>
#define MAX 5
int q[MAX];
int front = -1;
int rear = -1;

void Enqueue()
{
    int num;
    printf("Enter the value to be inserted in the queue:");
    scanf("%d", &num);
    if ((front == 0 && rear == MAX - 1) || (rear == front - 1))
    {
        printf("Queue is FULL");
    }
    else if (rear == -1 && front == -1)
    {
        front = rear = 0;
        q[rear] = num;
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        q[rear] = num;
    }
    else
    {
        rear++;
        q[rear] = num;
    }
}
void Dequeue()
{
    int num;
    if (front == -1)
    {
        printf("Queue is EMPTY");
    }
    num = q[front];

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == MAX - 1)
            front = 0;
        else
            front++;
    }
    printf("The deleted element is :%d\n", num);
}
void peek()
{
    if (front == -1)
    {
        printf("Queue is EMPTY");
    }
    else
    {
        printf("The first element in queue is:%d\n", q[front]);
    }
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is EMPTY");
    }
    else
    {
        printf("The elements in the queue are:\n");

        if (front <= rear)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", q[i]);
            }
        }
        else
        {
            for (i = front; i < MAX; i++)
                printf("%d ", q[i]);
            for (i = 0; i <= rear; i++)
                printf("%d ", q[i]);
        }
    }
}

void main()
{
    int choice;
    do
    {
        printf("\nenter 1 for inserting an element\n");
        printf("enter 2 for deleting an element\n");
        printf("enter 3 to peek the first  element\n");
        printf("enter 4 for displaying the queue\n");
        printf("enter 5 to EXIT\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);

        printf("\n");

        switch (choice)
        {
        case 1:
            Enqueue();
            break;
        case 2:
            Dequeue();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        }
    } while (choice != 5);
    getch();
}