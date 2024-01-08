#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("\nMemory allocation failed");
    }
    newnode->data=data;
    newnode->next=NULL;

    return newnode;
}
void display(struct node *head)
{
    struct node *ptr=head;
    while(ptr!=NULL)
    {
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
void middle(struct node *head)
{
    struct node *ptr1=head;
    struct node *ptr2=head;

    while(ptr2!=NULL && ptr2->next!=NULL)
    {
        ptr1=ptr1->next;
        ptr2=ptr2->next->next;
    }

    printf("%d ",ptr1->data);

}
int main()
{
    struct node *head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    head->next->next->next->next=createnode(5);
    head->next->next->next->next->next=createnode(6);
    display(head);
    middle(head);

    
    return 0;
}
