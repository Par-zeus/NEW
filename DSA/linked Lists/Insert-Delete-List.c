#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *insert_at_beginning(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;
    return head;
}

struct Node *insert_at_index(struct Node *head, int index, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i += 1;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
void display(struct Node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *insert_at_end(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (p->next != NULL)
    {
        p = p->next;
        i += 1;
    }

    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}
struct Node *del_at_beginning(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct Node *del_at_index(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i += 1;
    }
    p->next = q->next;
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

    if (p->data == data)
    {
        head = del_at_beginning(head);
        return head;
    }
    while (q->data != data && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data = data)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("\nValue not found\n");
    }
    return head;
}
struct Node *create_ll(struct Node *start)
{
    struct Node *new_Node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    {
        new_Node = (struct Node *)malloc(sizeof(struct Node));
        new_Node->data = num;
        if (start == NULL)
        {
            new_Node->next = NULL;
            start = new_Node;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = new_Node;
            new_Node->next = NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}
void main()
{
    struct Node *head;
    // struct Node *second;
    // struct Node *third;
    // struct Node *fourth;

    int n, i, x, index, choice;
    head = (struct Node *)malloc(sizeof(struct Node));
    // second = (struct Node *)malloc(sizeof(struct Node));
    // third = (struct Node *)malloc(sizeof(struct Node));
    // fourth = (struct Node *)malloc(sizeof(struct Node));

    // head=NULL;
    // printf("List is:\n");
    // head->data = 79;
    // head->next = second;

    // second->data = 67;
    // second->next = third;

    // third->data = 69;
    // third->next = fourth;

    // fourth->data = 99;
    // fourth->next = NULL;
    // display(head);

    do
    {
        printf("\nEnter 1 for insertion at beginning\n 2 for insertion at index\n 3 for insertion at the end\n");
        printf(" 4 for deletion at the beginning\n 5 for deletion at given index\n 6 for deletion at the end\n 7 for deletion of a given value");
        printf("\n enter 8 for creating node: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:

            printf("Enter the elements of the list:");
            scanf("%d", &n);

            // Inertion at beginning
            for (i = 0; i < n; i++)
            {
                printf("Enter the number : ");
                scanf("%d", &x);
                head = insert_at_beginning(head, x);
            }
            printf("New List is:\n");
            display(head);
            break;
        // Insertion at index
        case 2:
            printf("Enter the element which you want to insert:");
            scanf("%d", &x);
            printf("Enter the index after which you want to insert a element: ");
            scanf("%d", &index);
            head = insert_at_index(head, index, x);

            printf("New List is:\n");
            display(head);
            break;
            // Insertion at the end
        case 3:
            printf("Enter the element to be inserted at the end:");
            scanf("%d", &x);
            head = insert_at_end(head, x);
            printf("New List is:\n");
            display(head);
            break;
            // deletion at the begnning
        case 4:
            head = del_at_beginning(head);
            printf("New List is:\n");
            display(head);
            break;
            // deletion at index
        case 5:
            printf("Enter the index at which you want to delete the element:");
            scanf("%d", &index);
            head = del_at_index(head, index);
            printf("New List is:\n");
            display(head);
            break;
            // deletion at the end
        case 6:
            head = del_at_end(head);
            printf("New List is:\n");
            display(head);
            break;
            // deletion of a value
        case 7:
            printf("Enter the value which you want to delete from the list :");
            scanf("%d", &x);
            head = del_for_value(head, x);
            display(head);
            break;
        case 8:
            head = create_ll(head);
        }
    } while (choice != 9);
    getch();
}