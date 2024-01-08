#include <stdio.h>
#include <stdlib.h>

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
    if(head==NULL)
    {
        printf("There is no list\n");
    }
    struct node *ptr = head;
    do
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
  
    printf(" %d\n", head->data);
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
struct node *del_head(struct node *head)
{
    struct node *p=head;
    struct node *last=head;


    while(last->next!=head)
    {
        last=last->next;
    }

    // p->next=p->next->next;
    head=head->next;
    last->next=head;
    free(p);

    return head;
}
struct node *insert_anywhere(struct node *head,int data,int aftervalue)
{
    struct node *ptr=createnode(data);
    struct node *p=head;
    // if(p->data==aftervalue)
    // {
    //     printf("There is no value head value");
    // }
    do
    {
        p=p->next;

    } while(p->data!=aftervalue && p!=head);

    if (p == head)
    {
        printf("Value %d not found in the list.\n", aftervalue);
        free(ptr);
        return head;
    }
    
    ptr->next=p->next;
    p->next=ptr;

    return head;
}
struct node *del_value(struct node *head,int value)
{
    struct node *p=head;
    if(head==NULL)
    {
        printf("List is empty");
        return head;
    }
    do
    {
        p=p->next;
    } while (p->next->data!=value && p!=head);

    if(p==head)
    {
        printf("Value %d not found",value);
    }

    struct node *q=p->next;
    p->next=q->next;
    free(q);

    return head;
}
int main()
{
    int choice,value,afterval;

    struct node *head = createnode(1);
    struct node *p = head;
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);

    head->next->next->next->next->next = p;
    // display(head);

    printf("\nMain Menu");
    printf("\n1.Display");
    printf("\n2.Insert at the end before head");
    printf("\n3.Delete head");
    printf("\n4.Insert after value");
    printf("\n5.Delete for a given value");
    printf("\n-1 to Exit");

    while (choice != -1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            display(head);
            break;

        case 2:
            printf("Enter the value to be inserted:");
            scanf("%d",&value);
            head = insert_last(head,value);
            break;

        case 3:
            head = del_head(head);
            break;
    
        case 4:
            printf("Enter the value to be inserted:");
            scanf("%d",&value);
            printf("Enter the value after which %d is to be inserted",value);
            scanf("%d",&afterval);
            head=insert_anywhere(head,value,afterval);
            break;
        case 5:
            printf("Enter the value to be deleted:");
            scanf("%d",&value);
            head=del_value(head,value);
            break;

        case -1:
            exit(1);
        default:
            printf("Invalid choice");
        }
    }

    return 0;
}