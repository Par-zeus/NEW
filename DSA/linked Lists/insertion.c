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

struct Node *insert_at_node(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
void main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st and 2nd nodes
    head->data = 7;
    head->next = second;

    // link 2nd and 3rd nodes
    second->data = 17;
    second->next = third;

    // terminate list at the third node
    third->data = 76;
    third->next = NULL;

    traversal(head);

    printf("After insertion :\n");
    head = insert_at_beginning(head, 45);
    traversal(head);

    printf("After insertion at between:\n ");
    head = insert_at_index(head, 2, 50);
    traversal(head);

    printf("After insertion at the end:\n");
    head = insert_at_end(head, 99);
    traversal(head);

    printf("Insertion after a Node: \n");
    head = insert_at_node(head, second, 67);
    traversal(head);
    getch();
}
