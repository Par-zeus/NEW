#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=head;
    return newnode;
}

void display(struct node *head)
{
    struct node *ptr=head;
    do{
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("%d\n",ptr->data);
 
}
struct node *del_beg(struct node *head)
{
    struct node *p=head;
    struct node *last=head->next;

    while(last->next!=head)
    {
        last=last->next;
    }
    head=head->next;
    last->next=head;;
    free(p);
    return head;

}
struct node *insert_last(struct node *head,int data)
{
    struct node *p=head;
    struct node *ptr=createnode(data);

    while(p->next!=head)
    {
        p=p->next;
    }

    p->next=ptr;
    ptr->next=head;
    return head;


}
int main()
{
   head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    head->next->next->next->next=createnode(5);
    display(head);

    // insert_after(head,78,6);
    // display(head);
    
    // insert_before(head,78,7);
    // display(head);

    // del1(head,1);
    // display(head);
    
    // head=del_beg(head);
    // display(head);

      head=insert_last(head,56);
    display(head);

    return 0;
}
