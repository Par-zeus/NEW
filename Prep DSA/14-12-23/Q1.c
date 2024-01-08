#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    return newnode;
}

struct node *insert_at_end(struct node *head, int data)
{
    struct node *current = head;
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    while (current->next != NULL)
    {
        current = current->next;
    }
    ptr->data = data;
    current->next = ptr;
    ptr->next = NULL;

    return head;
}
struct node *del_after_value(struct node *head, int aftervalue)
{
    struct node *p = head;

    // Check if the list is empty
    if (p == NULL)
    {
        printf("List is empty.\n");
        return head;
    }

    while (p != NULL && p->data != aftervalue)
    {
        p = p->next;
    }

    if (p == NULL || p->next == NULL)
    {
        printf("Value %d not found in the list or it's the last node.\n", aftervalue);
        return head;
    }

    struct node *q = p->next;
    p->next = q->next;
    free(q);

    return head;
}


struct node *insert_after_value(struct node *head, int data, int pos)
{
    struct node *current = head;
    struct node *ptr = createnode(data);

    while (current->data != pos && current != NULL)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        printf("Value %d not found in the list.\n", pos);
        return head;
    }

    ptr->next = current->next;
    current->next = ptr;

    return head;
}

void display(struct node *head)
{
    struct node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d ->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = createnode(1);
    head->next = createnode(2);
    head->next->next = createnode(3);
    head->next->next->next = createnode(4);
    head->next->next->next->next = createnode(5);
    // display(head);
    int choice, value;
    int valin, valalr;

    printf("\nMain Menu");
    printf("\n1.Insert at end");
    printf("\n2.Insert after value");
    printf("\n4.Delete after value:");
    printf("\n3.Display elements");
    printf("\n -1 to exit");

    while (choice != -1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to be inserted at end:");
            scanf("%d", &value);

            head = insert_at_end(head, value);
            break;

        case 2:
            printf("Enter the value to be inserted:");
            scanf("%d", &valin);
            printf("Enter the value after which u want to insert %d:", valin);
            scanf("%d", &valalr);
            head = insert_after_value(head, valin, valalr);
            break;

        case 3:
            display(head);
            break;

        case 4:
        printf("Enter the value of previous node of the node which u want to delete:");
        scanf("%d",&value);
        head=del_after_value(head,value);
        break;
        case -1:
            exit(1);
            break;
        default:
            printf("Invalid choice");
        }
    }
    return 0;
}