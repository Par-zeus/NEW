#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

struct node *insert_beg(struct node *head, int data)
{
    struct node *p = createnode(data);
    p->prev = NULL;
    p->next = head;
    head->prev = p;
    head = p;

    return head;
}
struct node *insert_end(struct node *head, int data)
{
    struct node *ptr = createnode(data);
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;

    return head;
}
struct node *insert_after(struct node *head, int data, int aftervalue)
{
    struct node *ptr = createnode(data);
    struct node *p = head;

    while (p != NULL && p->data != aftervalue)
    {
        p = p->next;
    }

    if (p != NULL)
    {
        struct node *q = p->next;
        ptr->next = q;
        if (q != NULL)
        {
            q->prev = ptr;
        }
        p->next = ptr;
        ptr->prev = p;
    }
    else
    {
        printf("\nValue %d not found in the list.\n", aftervalue);
    }

    return head;
}
struct node *delete_beg(struct node *head)
{
    struct node *p = head;
    head = head->next;
    head->prev = NULL;
    free(p);

    return head;
}
struct node *delete_end(struct node *head)
{
    struct node *p = head;
    struct node *q = p->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}
struct node *delete_after(struct node *head, int aftervalue)
{
    struct node *p = head;

    while (p != NULL && p->data != aftervalue)
    {
        p = p->next;
    }

    if (p != NULL)
    {
        struct node *q = p->next;
        if (q != NULL)
        {
            p->next = q->next;
            if (q->next != NULL)
            {
                q->next->prev = p;
            }
            free(q);
        }
        else
        {
            printf("\nNo element after %d to delete.\n", aftervalue);
        }
    }
    else
    {
        printf("\nValue %d not found in the list.\n", aftervalue);
    }
    return head;
}
void display(struct node *head)
{
    struct node *p = head;

    printf("\nNULL-> ");
    while (p != NULL)
    {
        printf("%d-> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}
void find(struct node *head)
{
    struct node *p = head;
    struct node *q = head;

    int x,y;
    x=y=head->data;

   while (p != NULL) {
        if (p->data < x) {
            x = p->data;
        }
        if (p->data > y) {
            y = p->data;
        }
        p = p->next;
    }
    printf("\nSmallest element :%d", x);
    printf("\nLargest element :%d", y);

}
int main()
{
    struct node *head = createnode(1);
    int choice, value, after;
    printf("\nMain menu");
    printf("\n1.Insert at beg");
    printf("\n2.Insert at end");
    printf("\n3.Insert after value");
    printf("\n4.delete at beginning");
    printf("\n5.delete at end");
    printf("\n6.delete after value");
    printf("\n7.display");
    printf("\n8.Minimum element");
    printf("\n-1 to exit");

    while (choice != -1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter value tobe inserted:");
            scanf("%d", &value);
            head = insert_beg(head, value);
            break;
        case 2:
            printf("\nEnter value tobe inserted:");
            scanf("%d", &value);
            head = insert_end(head, value);
            break;
        case 3:
            printf("\nEnter value to be inserted:");
            scanf("%d", &value);
            printf("\nEnter value after which you want to insert:");
            scanf("%d", &after);
            head = insert_after(head, value, after);
            break;
        case 4:
            head = delete_beg(head);
            break;
        case 5:
            head = delete_end(head);
            break;
        case 6:
            printf("\nEnter value after which the element is to be deleted:");
            scanf("%d", &after);
            head = delete_after(head, after);
            break;
        case 7:
            display(head);
            break;
        case 8:
            find(head);break;
        case -1:
            exit(1);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}
