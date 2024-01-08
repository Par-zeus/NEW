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

void display(struct node *head)
{
    struct node *ptr = head;
    printf("NULL ->");
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
struct node *insert_after(struct node *head, int data, int afterval)
{
    struct node *p = head;
    // struct node *q = p->next;
    struct node *ptr = createnode(data);
   
    while (p != NULL && p->data != afterval)
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
        printf("\nValue %d not found in the list.\n", afterval);
    }

    return head;
}
struct node *insert_beg(struct node *head, int value)
{
    struct node *p = head;
    struct node *ptr = createnode(value);

    ptr->prev = NULL;
    ptr->next = p;
    p->prev = ptr;
    head = ptr;
    return head;
}

struct node *insert_end(struct node *head, int value)
{
    struct node *p = head;
    struct node *ptr = createnode(value);

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;

    return head;
}
void reverse(struct node *head)
{
    struct node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    printf("NULL ->");
    while (p != NULL)
    {
        printf("%d ->", p->data);
        p = p->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = createnode(1);

    head = insert_beg(head, 2);
    head = insert_end(head, 4);
    head = insert_beg(head, 3);
    head = insert_end(head, 5);

    display(head);
    // reverse(head);
    head = insert_after(head, 34, 98);
    display(head);

    return 0;
}
