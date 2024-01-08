#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
void display(struct Node *head)
{
    struct Node *ptr = head;
    // printf("%d ", ptr->data);
    // ptr = ptr->next;
    // while (ptr != head)
    // {
    //     printf("%d ", ptr->data);
    //     ptr = ptr->next;
    // }

    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct Node *insert_at_beginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head->next;
    ptr->data = data;

    while (p->next != head)
    {
        p = p->next;
    } // p points to the last node of circular linked list

    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
}
void main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;
    int n, x, i;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 7;
    head->next = second;

    second->data = 17;
    second->next = third;

    third->data = 76;
    third->next = fourth;

    fourth->data = 68;
    fourth->next = head;

    printf("List is:\n");
    display(head);
    
    printf("\nEnter the element to be added :");
    scanf("%d", &x);
    
    head = insert_at_beginning(head, x);
    printf("New List is:\n");
    display(head);

    getch();
}