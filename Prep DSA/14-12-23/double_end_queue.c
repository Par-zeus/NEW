#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int st[MAX],front=-1,rear=-1;
void insert_rear(int value)
{
    if(rear==(rear+1)%MAX)
    {
        printf("\nQueue is FULL");
    }
    else if(front==-1 || rear==-1)
    {
        front=rear=0;
        st[rear]=value;
    }
    else if(rear==MAX-1)
    {
        rear=0;
        st[rear]=value;
    }
    else{
        rear++;
        st[rear]=value;
    }
}
void insert_front(int value)
{
    if(front==(rear+1)%MAX)
    {
        printf("\nQueue is FULL");
    }
    else if(front==-1 || rear==-1)
    {
        front=rear=0;
        st[front]=value;
    }
    else if(front==0)
    {
        front=MAX-1;
        st[front]=value;
    }
    else{
        front--;
        st[front]=value;
    }
}
void delete_front()
{
    int value=st[front];
    printf("\nDeleted element: %d",value);
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(front==MAX-1)
    {
        front=0;
    }
    else{
        front++;
    }
}
void delete_rear()
{
    int value=st[rear];
    printf("\nDeleted element: %d",value);
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        front=rear=-1;
    }
    else if(rear==0)
    {
        rear=MAX-1;
    }
    else{
        rear--;
    }
}
void display() {
    if (front == -1) {
        printf("\nQueue is empty");
    } else {
        int i = front;
        while (i != rear) {
            printf("%d ", st[i]);
            i = (i + 1) % MAX;
        } 
        printf("%d ",st[rear]);
    }
}
void main()
{
        int option,value;
        printf("\n 1.Insert at rear");
        printf("\n 2.Delete from front");
        printf("\n 3.Delete from rear");
        printf("\n 4.Insert from front");
        printf("\n 5.Display");
        printf("\n -1.Quit");
    do {
        
        // printf("\n INPUT RESTRICTED DEQUE");
        
        printf("\n Enter your option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
            printf("\nEnter value to be inserted:");
            scanf("%d",&value);
                insert_rear(value);
                break;
            case 2:
                delete_front();
                break;
            case 3:
                delete_rear();
                break;
            case 4:
            printf("\nEnter value to be inserted:");
            scanf("%d",&value);
            insert_front(value);
            break;    
            case 5:
                display();
                break;
            case -1:exit(1);break;
            default:printf("\nInvalid choice"); 

        }
    } while (option !=-1 );
}
