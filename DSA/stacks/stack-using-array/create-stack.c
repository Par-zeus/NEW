#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void main()
{
    // struct stack s;
    // s.size=80;
    // s.top=-1;
    // s.arr=(int *)malloc(s.size*sizeof(int));

    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
printf("Hello");
    s->arr[0] = 4;
    s->top++;

    if (isEmpty(s))
    {
        printf("Stack is empty");
    }
    else
    {
        printf("Stack is not empty");
    }

    getch();
}