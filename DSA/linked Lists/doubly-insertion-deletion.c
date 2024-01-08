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
    printf("New List:\n");
    printf(" 1st Element:%d\n", ptr->data);

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
    }
}
struct Node *insert_at_beginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->prev = NULL;
    ptr->next = head;
    head = ptr;
    return head;
}
struct Node *insert_at_index(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    struct Node *q = head->next;

    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    ptr->prev = p;
    p->next = ptr;
    q->prev = ptr;

    return head;
}
struct Node *insert_at_end(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}
struct Node *del_at_beginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}
struct Node *del_at_index(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    struct Node *r = q->next;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        r = r->next;
        i+=1;
    }

    p->next = q->next;
    r->prev = p;

    free(q);
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
struct Node *del_for_value(struct Node *head, int data)
{
    struct Node *p = head;
    struct Node *q = head->next;
    struct Node *r = q->next;
    
    if(p->data==data)
    {
        head = del_at_beginning(head);
        return head;
    }
    
    while (q->next != NULL)
    {
          if (q->data == data)
        {
            p->next = q->next;
            r->prev = p;
            free(q);
        }
     
        p = p->next;
        q = q->next;
        r = r->next;
        if(r->data==data)
        {
            head=del_at_end(head);
            return head;
        }
         
         if(q->data!=data && r->data!=data)
         { 
            printf("\nElement Not Found\n");
         }
    }

    // if (q->data == data)
    // {
    //     p->next = q->next;
    //     r->prev = p;
    //     free(q);
    // }
    // else
    // {
    //     printf("\nElement Not Found\n");
    // }
    return head;
    
}
void main()
{

    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    int n, x, index, choice;

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

    printf("Original List is:\n");
    traversal(head);

    printf("Enter 1 for insert at beginning\n 2 for insert at index\n 3 for insert at end \n");
    printf("4 for deletion at beginning\n 5 for deletion at index\n 6 for deletion at the end\n 7 for deletion of a particular value:");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the element to be inserted:");
        scanf("%d", &x);

        head = insert_at_beginning(head, x);
        traversal(head);
        break;
    case 2:
        printf("Enter the index after which the number is to be inserted:");
        scanf("%d", &index);
        printf("Enter the element to be inserted:");
        scanf("%d", &x);

        head = insert_at_index(head, x, index);
        traversal(head);
        break;

    case 3:
        printf("Enter the element to be inserted:");
        scanf("%d", &x);

        head = insert_at_end(head, x);
        traversal(head);
        break;

    case 4:
        head = del_at_beginning(head);
        traversal(head);
        break;

    case 5:
        printf("Enter the index after which you want to delete :");
        scanf("%d", &index);
        head = del_at_index(head, index);
        traversal(head);
        break;

    case 6:
        head = del_at_end(head);
        traversal(head);
        break;

    case 7:
        printf("Enter the value you want to delete:");
        scanf("%d", &x);
        head = del_for_value(head, x);
        traversal(head);
        break;

    default:
        printf("Invalid input");
    }

    getch();
}
