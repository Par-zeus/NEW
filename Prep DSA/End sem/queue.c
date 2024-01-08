#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int st[MAX];
int front=-1,rear=-1;

void insert(int st[],int value)
{
    if(rear==MAX-1)
    {
        printf("\nQueue is Full");
    }
    else if(front==rear)
    {
        front++;
        rear++;
        st[rear]=value;
    }else{
        st[++rear]=value;
    }
}
void delete(int st[])
{
    int value=st[front];
    if(front==-1)
    {
        printf("\nQueue is Empty");
    }else if(front==rear)
    {
        front=rear=-1;
    }else{
        front++;
    }
}
void display(int st[]) {
    if (front == -1) {
        printf("\nQueue is Empty");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", st[i]);
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
    printf("\n-1.Exit");
    while(choice!=-1)
    {
         printf("\nEnter your choice:");
            scanf("%d",&choice);
        switch(choice)
        {
           
            case 1:
            printf("\nEnter value to be inserted:");
            scanf("%d",&value);
            insert(st,value);break;
            case 2:delete(st);break;
            case 3:display(st);break;
            case -1:exit(1);
            default:printf("\nInvalid choice");

        }
    }
    return 0;

}