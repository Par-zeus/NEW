#include<stdio.h>
#include<stdlib.h>
# define MAX 5
int front=-1;
int rear=-1;
int st[MAX];
void insert(int st[],int value)
{
    if(front==-1 && rear==-1)
    {
        front=rear=0;
        st[rear]=value;
    }
    else if( ((rear+1)%MAX)==front)
    {
        printf("\nQueueis full");
    }
    else{
        rear=(rear+1)%MAX;
        st[rear]=value;
    }
}
void delete(int st[])
{
    int value=st[front];
    printf("\nDeleted element : %d",value);
   if(front==-1 )
   {
    printf("\nQueue is empty");
   }
   else if(front==rear)
   {
    front=rear=-1;
   }
   else{
    front=(front+1)%MAX;
   }
}
void display(int st[]) {
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