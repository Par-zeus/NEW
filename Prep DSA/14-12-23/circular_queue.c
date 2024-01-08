#include<stdio.h>
#include<stdlib.h>
# define MAX 10
int front=-1;
int rear=-1;
int st[MAX];
void insert(int st[],int value)
{
    if(front==0 && rear==MAX-1)
    {
        printf("\n Queue if full");
    }
    else if(front==-1 && rear==-1)
    {
       front=rear=0;
        st[rear]=value;
    }
    else if(rear==MAX-1 && front!=0)
    {
        rear=0;
        st[rear]=value;
    }
    else{
        st[++rear]=value;
    }

}
void delete(int st[])
{
    int value=st[front];
    if(front ==-1)
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
    printf("\nDeleted element: %d",value);
}
void display(int st[])
{
    if(front ==-1)
    {
        printf("\nQueue is empty");
    }else{
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",st[i]);
        }
    }

}

int main()
{
    int choice,value;
    printf("\nMain Menu");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Display");
    printf("\n-1 to exit");

    while(choice!=-1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("\nEnter the value to be inserted:");
            scanf("%d",&value);
            insert(st,value);
            break;

            case 2:
            delete(st);
            break;

            case 3:
            display(st);
            break;

            case -1:exit(1);
            default:printf("Invalid choice");
        }
    }
   return 0; 
}