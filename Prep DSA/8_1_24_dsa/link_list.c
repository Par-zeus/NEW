#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
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

struct node *insert_after(struct node *head,int value,int aftervalue)
{
    struct node *p=head;
    struct node *ptr=createnode(value);

    while(p->data!=aftervalue && p->next!=NULL)
    {
        p=p->next;
    }
    if(p->data!=aftervalue)
    {
        printf("\nAftervalue not found");
    }else{
    ptr->next=p->next;
    p->next=ptr;
    }
    return head;
}
struct node *insert_before(struct node *head,int value,int beforevalue)
{
    struct node *p=head;
    struct node *ptr=createnode(value);

    while(p->next->data!=beforevalue && p->next!=NULL)
    {
        p=p->next;
    }
    if(p->next->data!=beforevalue)
    {
        printf("\nBeforevalue not found");
    }else{
        ptr->next=p->next;
        p->next=ptr;
    }
    return head;
}
struct node *del(struct node *head,int value)
{
    struct node *p=head;
    struct node *q=p->next;

    if(p!=NULL && p->data==value)
    {
        head=head->next;
        free(p);
        return head;
    }
    while(q->data!=value && q!=NULL)
    {
        q=q->next;
        p=p->next;
    }
    p->next=q->next;
    free(q);
    return head;
}
struct node *del_beg(struct node *head)
{
    struct node *p=head;
    head=head->next;
    free(p);
    return head;

}
// struct node *del1(struct node *head,int value)
// {
//     struct node *p=head;
//     struct node *q=NULL;

//     if(p!=NULL && p->data==value)
//     {
//         head=del_beg(head);
//         return head;
//     }else{
//     while(p->data!=value && p!=NULL)
//     {
//         q=p;
//         p=p->next;
//     }
//     q->next=p->next;
//     free(p);
//     return head;
//     }
// }
struct node *del1(struct node *head, int value) {
    struct node *p = head;
    struct node *q = NULL;

    // Check if the first node contains the value to delete
    if (p != NULL && p->data == value) {
        head = p->next;
        free(p);
        return head;
    }

    // Traverse the list to find the node with the value to delete
    while (p != NULL) {
        if (p->data == value) {
            break;
        }
        q = p;
        p = p->next;
    }

    // If the value is found, remove the node
    if (p != NULL) {
        q->next = p->next;
        free(p);
    } else {
        printf("\nValue not found");
    }

    return head;
}

int main()
{
    struct node *head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    head->next->next->next->next=createnode(5);
    display(head);

    // insert_after(head,78,6);
    // display(head);
    
    // insert_before(head,78,7);
    // display(head);

    head=del1(head,2);
    display(head);

    return 0;
}