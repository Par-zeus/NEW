#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\n memory failure");
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void display(struct node *head)
{
    int c=0;
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    
    while(ptr!=NULL){
        printf("%d ->",ptr->data);
        ptr=ptr->next;
        c++;
    }
    printf("NULL\n");
    printf("\nNumber of nodes :%d",c);
    printf("\n");
}
int main()
{
    head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    head->next->next->next->next=createnode(5);
    display(head);
    return 0;

}