#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;    
};
struct Node *insert_at_end(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head; // making p as my head

    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;

    return head;
}
struct Node *insert_at_beginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    head = ptr;
    return head;
}
struct Node *insert_at_index(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head; // making p as my head

    int i = 0;

    while (i != index - 1)
    {
        p = p->next; // iterate to (index-1)th position where we want to insert
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node *insert(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

void main()
{

    struct Node *head;
    int n, i, x, index;
    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    head = NULL;
    printf("Enter the nos: ");
    scanf("%d", &n);

// Insertion at beginning

    for (i = 0; i < n; i++)
    {
        printf("Enter the number: \n");
        scanf("%d", &x);
        head = insert(head, x);
    }
    traversal(head);

    
    // printf("Enter the number to be inserted at beginning: ");
    // scanf("%d", &x);
    // printf("After insertion :\n");
    // head = insert_at_beginning(head, x);
    // traversal(head);


// Insertion at Index

    printf("Enter the number to be inserted after the index: ");
    scanf("%d", &x);
    printf("Enter the index: ");
    scanf("%d", &index);
    printf("After insertion at between:\n ");
    head = insert_at_index(head, index, x);
    traversal(head);


//Insertion at end


    printf("Enter the number to be inserted at the end: ");
    scanf("%d", &x);
    printf("After insertion at the end:\n");
    head = insert_at_end(head, x);
    traversal(head);

    getch();
}
