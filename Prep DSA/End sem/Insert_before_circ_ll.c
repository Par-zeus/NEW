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
    newnode->next=head;
    return newnode;
}

void display(struct node *head)
{
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("\nList is empty");
    }
    
    do{
        printf("%d ->",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
    printf("%d",ptr->data);
    printf("\n");
}

struct node *insert_before(struct node *head, int data, int bef) {
    struct node *p = head;
    struct node *ptr = createnode(data);

    if (head->data == bef) {
        while (p->next != head) {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        return ptr;
    }

  do {
        p = p->next;
    }   while (p!= head && p->next->data != bef);

    ptr->next = p->next;
    p->next = ptr;

    return head;
}

int main()
{
    head=createnode(1);
    struct node *p=head;
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);

    head->next->next->next->next=p;

    display(head);

    head=insert_before(head,34,2);
    display(head);


    return 0;
}