#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

void traversal(struct Node *ptr)
{
        printf(" 1st Element:%d\n", ptr->data);
        int i=0;
    while (ptr != NULL)
    {
        // Print the previous element
        if (ptr->prev != NULL)
            printf("Previous Element:%d ", ptr->prev->data);
        else
            printf("Previous Element: None ");
        printf("\n");
        // Print the next element
        if (ptr->next != NULL)
            printf("Next Element:%d ", ptr->next->data);
        else
            printf("Next Element: None ");
        printf("\n");
        ptr = ptr->next;
        i+=1;
    }
}

void main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    int n,x,i;

    // Allocate memory for nodes in the linked list in Heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st and 2nd nodes
    head->data = 7;
    head->next = second;
    head->prev = NULL;

    // link 2nd and 3rd nodes
    second->data = 17;
    second->next = third;
    second->prev = head;

    // terminate list at the third node
    third->data = 76;
    third->next = fourth;
    third->prev = second;

    fourth->data = 78;
    fourth->prev = third;
    fourth->next = NULL;

    traversal(head);

   


    getch();
}
