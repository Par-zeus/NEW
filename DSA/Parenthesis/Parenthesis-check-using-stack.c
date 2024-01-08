
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// "(" -> if yes then push into the stack
// ")" -> if yes then pop into the stack

struct stack
{
    int size;
    int top;
    char *arr; // use to dynamically allocate memeory
};
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1; // if stack is full
    }
    else
    {
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1; // if stack is empty
    }
    else
    {
        return 0;
    }
}
// push():adds element at thr top of stack
char push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow");
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
    }
}
// pop():remove the top element from the stack
char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char value = ptr->arr[ptr->top];
        ptr->top--;
        return value;
        // printf("Popped %d from stack\n", value);
    }
}


int parenthesismatch(char *exp)
{
    struct stack *sp= (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(sp, '(');
        }
        else if (exp[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if(isEmpty(sp)){
        return 1;
    }
    else{
        return 0;
    }
}
void main()
{
    char exp[100];
    printf("Enter the expression: ");
    gets(exp);
    if (parenthesismatch(exp))
    {
        printf("Parenthesis matches");
    }
    else
    {
        printf("Parenthesis not matches");
    }

    getch();
}
