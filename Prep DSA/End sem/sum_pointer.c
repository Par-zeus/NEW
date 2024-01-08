#include <stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *createnode(int data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
void display(struct node *head)
{
    struct node *p=head;
    while(p!=NULL){
        printf("%d ->",p->data);
        p=p->next;
    }
    printf("NULL\n");

}
struct node *reverse(struct node *head)
{
    struct node *current=head;
    struct node *prev=NULL;
    struct node *forward;

    while(current!=NULL)
    {
        forward=current->next;
        current->next=prev;
        prev=current;
        current=forward;
    }

    return prev;
}
struct node *sort(struct node *head)
{
    struct node *ptr1=head;
    struct node *ptr2;  
    int temp;

    while(ptr1!=NULL)
    {
        ptr2=ptr1->next;
        while(ptr2!=NULL)
        {
            if(ptr1->data > ptr2->data)
            {
                temp=ptr1->data;
                ptr1->data=ptr2->data;
                ptr2->data=temp; 
            }
            ptr2=ptr2->next;
        }
            ptr1=ptr1->next;
    }
    return head;

}
int main()
{
   
    struct node *head=createnode(1);
    head->next=createnode(3);
    head->next->next=createnode(2);
    head->next->next->next=createnode(6);
    head->next->next->next->next=createnode(4);

    display(head);

    struct node *temp=sort(head);
    display(temp);

     struct node *rev=reverse(head);
    display(rev);

   

}