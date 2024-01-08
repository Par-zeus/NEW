#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int st[MAX], top = -1;
void push(int st[], int value)
{
    if (top == MAX - 1)
    {
        printf("\nStack OVERFLOW");
    }
    else
    {
        st[++top] = value;
    }
}
void pop(int st[])
{
    if (top == -1)
    {
        printf("\nStack UNDERFLOW");
    }
    else
    {
        int value = st[top];
        top--;
        printf("The popped element is :%d", value);
    }
}
void peek(int st[])
{
    if (top == -1)
    {
        printf("\nStack is EMPTY");
    }
    else
    {
        printf("The peek element is :%d", st[top]);
    }
}
void display(int st[])
{
    if (top == -1)
    {
        printf("\nStack is EMPTY");
    }
    else
    {
        for (int i = 0; i <= top; i++)
        {
            printf(" %d", st[i]);
        }
    }
}
int main()
{
    int choice, value;

    while (choice != 5)
    {
        printf("\n Enter 1 for push");
        printf("\n Enter 2 for pop");
        printf("\n Enter 3 for peek");
        printf("\n Enter 4 for display all elements");
        printf("\n Enter 5 for EXIT");

        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
        case 1:
            printf("\nEnter the values that is to be inserted into the stack:");
            scanf("%d", &value);
            push(st, value);
            break;
        case 2:
            pop(st);
            break;
        case 3:
            peek(st);
            break;
        case 4:
            display(st);
            break; 
        }
    } 
    return 0;
}