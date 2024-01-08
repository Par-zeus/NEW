#include <stdio.h>
#include <conio.h>
#define MAX 10
int q[MAX];
int front = -1;
int rear = -1;

void Enqueue()
{
    int num;
    printf("Enter the value to be inserted in the queue:");
    scanf("%d", &num);
  
    if (rear == MAX - 1)
    {
        printf("Queue is FULL");
    }
  
    else if (rear == -1 && front == -1)
    {
        front++;
        rear++;
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
    if (front == -1 )
    {
        printf("Queue is EMPTY");
    }
    else if (front == rear)
        {
            front = rear = -1;
        }
    else
    {
        num = q[front];
        front++;
    }    
        printf("The deleted element is :%d\n", num);
   
}
void peek()
{
    if (front == -1 || front > rear)
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
    if (front == -1 || front > rear)
    {
        printf("Queue is EMPTY");
    }
    else
    {
        printf("The elements in the queue are:\n");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", q[i]);
        }
        printf("\n");
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