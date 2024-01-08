#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node *top=NULL;

struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=top;
    top=newnode;
}
void push(int value)
{
    
}
int main()
{
    return 0;
}