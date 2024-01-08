#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int isFull(struct Node *top)
{
    // struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf(" Element:%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct Node *push(struct Node *top, int x)
{
    if (isFull(top))
    {
        printf("Stack Overflow");
    }
    else
    {
        struct Node *n = (struct Node *)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}
struct Node *pop(struct Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        struct Node *n = top;
        top = top->next;
        int x = n->data;
        free(n);
        printf("%d is being popped\n", x);
        return top;
    }
}
void peek(struct Node *top, int position)
{
    struct Node *ptr = top;
    int i, count = 0;
    for (i = 1; i <= position; i++)
    {
        if (ptr != NULL)
        {
            // printf("%d ", ptr->data);
            printf("Value at position %d is %d\n",i,ptr->data);
            ptr = ptr->next;
            count++;
        }
    }
    if (position > count)
    {
        printf("There are only %d elements in the stack\n", count);
    }
}
void stackTop(struct Node *top)
{
    printf("\nThe toppmost element is :%d\n", top->data);
}
void stackBottom(struct Node *top)
{
    struct Node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("The Bottommost element is :%d\n", ptr->data);
}
void main()
{
    int x, n, i;
    struct Node *top = NULL;

    printf("Enter the element to be pushed: ");
    scanf("%d", &x);

    top = push(top, x);
    // traversal(top);

    top = push(top, 345);
    top = push(top, 45);
    top = push(top, 435);
    top = push(top, 545);
   
    // Condition for stack overflow
    // while(1)
    // {
    // top = push(top, 1);
    // }

    printf("Elements left after pushing:\n");
    traversal(top);

    top = pop(top);
    printf("Elements left after popping:\n");
    traversal(top);

    printf("Enter the position upto which you want to see the element(s) :");
    scanf("%d", &n);

    printf("Element(s) you want to peek:\n");
    peek(top, n);
 

    stackTop(top);
    stackBottom(top);

    // traversal(top);

    getch();
}




// #include<stdio.h>
// #include<stdlib.h>

// struct Node
// {
//     int data;
//     struct Node *next;
// };

// void display(struct Node *ptr) {
//     printf("Elements of the linked list are:\n");
//     while(ptr != NULL) {
//         printf("%d\n",ptr->data);
//         ptr = ptr->next;
//     }
// }

// struct Node * insertAtFirst(struct Node *head, int data) {
//     struct Node *ptr =(struct Node*)malloc(sizeof(struct Node));
//     ptr->next = head;
//     ptr->data = data;
//     return ptr;
// }

// struct Node * insertAtEnd(struct Node *head,int data) {
//     struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
//     ptr->data = data;
//     ptr->next = head;
//     struct Node*p = head;
//     while(p->next!=NULL) {
//         p = p->next;
//     }
//     p->next = ptr;
//     ptr->next = NULL;
//     return head;
// }

// struct Node * insertInBetween(struct Node *head,int data,int index) {
//     struct Node * ptr = (struct Node*)malloc(sizeof(struct Node));
//     struct Node * p = head;
//     int i = 0;
//     while (i!=index-1) {
//         p = p->next;
//         i++;
//     }
//     ptr->data = data;
//     ptr->next = p->next;
//     p->next = ptr;
//     return head;
// }

// void main() {
//     struct Node *head;
//     struct Node *second;
//     struct Node *third;

//     head = (struct Node*)malloc(sizeof(struct Node));
//     second = (struct Node*)malloc(sizeof(struct Node));
//     third = (struct Node*)malloc(sizeof(struct Node));

//     head->data = 7;
//     head->next = second;

//     second->data = 11;
//     second->next = third;

//     third->data = 21;
//     third->next = NULL;

//     display(head);
//     // head = insertAtFirst(head,56);
//     // display(head);
//     // head = insertInBetween(head,28,2);
//     // display(head);
//     head=insertAtEnd(head,82);
//     display(head);
//     printf("%d",head->data);
//     getch();
// }