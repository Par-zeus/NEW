#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *del_at_beginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *del_in_between(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next; // this will point at one nodebefore which element is to be deleted
        q = q->next; // this will point at node which is to be deleted
        i++;
    }

    p->next = q->next; // Now p will point to node which is just after the deleted node and nothing will now point to deleted node
    free(q);           // freeing memory of q or deleted node

    return head;
}

struct Node *del_at_end(struct Node *head)
{

    struct Node *p = head;
    struct Node *q = head->next;

    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);

    return head;
}
struct Node *del_for_value(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;

    while (q->data != value && q->next != NULL) // loop will stop if  q ka data is null or pointing to null
    {
        p = p->next;
        q = q->next;
    }
    // Checking after end of loop if data is found  before pointing to NULL or not
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("value not found\n");
    }
    return head;
}
void main()
{
    int x, n, i, index;
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;

    printf("Enter the total numbers to be inserted: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number:");
        scanf("%d", &x);
        head = insert(head, x);
    }

    traversal(head);

    // Deletion at the beginning
    printf("After deleting at the beginning:\n");
    head = del_at_beginning(head);
    traversal(head);

    // Deletion in between
    printf("Enter the index after which the element is to be deleted: ");
    scanf("%d", &index);
    head = del_in_between(head, index);

    printf("After deletion in between:\n");
    traversal(head);

    // Deletion at the end
    printf("After deletion at the end:\n");
    head = del_at_end(head);
    traversal(head);

    // Deletion with a given value
    printf("Enter the element which is to be deleted:");
    scanf("%d", &x);
    head = del_for_value(head, x);
    traversal(head);

    getch();
}
