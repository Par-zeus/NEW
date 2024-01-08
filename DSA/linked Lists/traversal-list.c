#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

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

    getch();
}
