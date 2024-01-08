#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}
void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
struct node *mergedlist(struct node *head1,struct node *head2)
{
    struct node *p=head1;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=head2;
    printf("\nMerged list:");
    display(head1);

    return head1;
}

struct node *splitlist(struct node *mergedlist,int position)
{
    int count=1;
    struct node *p=mergedlist;
    while(count<position && p!=NULL)
    {
        p=p->next;
        count+=1;
    }
    struct node *list5=p->next;
    p->next=NULL;
    printf("\nList 4:");
    display(mergedlist);
    return list5;
}
int main()
{
    int position;
    struct node *head1 = createnode(1);
    head1->next = createnode(2);
    head1->next->next = createnode(3);
    head1->next->next->next = createnode(4);
    head1->next->next->next->next = createnode(5);

    struct node *head2 = createnode(6);
    head2->next = createnode(7);
    head2->next->next = createnode(8);
    head2->next->next->next = createnode(9);
    head2->next->next->next->next = createnode(10);

    printf("\nList 1:");
    display(head1);
    printf("\nList2:");
    display(head2);

    struct node *newhead=mergedlist(head1,head2);
    printf("\nEnter the position after which u want to split the merged list:");
    scanf("%d",&position);

    struct node *list5=splitlist(newhead,position);
    printf("\nList 5:");
    display(list5);
    return 0;
}