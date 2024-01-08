#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr; // use to dynamically allocate memeory
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
void push(struct stack *ptr, int value)
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
void pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        int value = ptr->arr[ptr->top];
        ptr->top--;
        printf("Popped %d from stack\n", value);
    }
}
// peek(): display the index of the element
void peek(struct stack *sp)
{
    int i;
    // if top=2 niche se 3rd element
    // and it is 1st element position wise then as per formula (top-i+1)  index will 2
     for (i = 1; i <= sp->top + 1; i++)
    {
     int arr_index = sp->top - i + 1;
        if (arr_index < 0)
        {
            printf("Not a valid position");  
        }
        else
        {
        // return sp->arr[arr_index];
        printf("The value at position %d is %d and index is %d\n", i, sp->arr[arr_index],arr_index);
        }

    }
}
void stackTop(struct stack *sp)
{
    printf("The topmost element of stack is: %d\n",sp->arr[sp->top]);
}
void stackBottom(struct stack *sp)
{
    printf("The bottommost element of stack is: %d\n",sp->arr[0]);
}
void main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    int n, i, x;
    // printf("Enter the size of stacck:");
    // scanf("%d",&n);
    // sp->size=n;

    sp->size = 40;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    // stack creation done successfully

    // printf("Before Pushing ,Empty:%d\n", isEmpty(sp));
    // printf("Before Pushing ,Full:%d\n", isFull(sp));
    push(sp, 87); // as arr size is 100 pushing one element means either full nor empty so return 0
    push(sp, 45);
    push(sp, 405);
    push(sp, 78);

    // printf("After pushing ,Empty:%d\n", isEmpty(sp));
    // printf("After pushing ,Full:%d\n", isFull(sp));

    // for(i=0;i<n;i++)
    // {
    //     printf("Enter the element you want to push into the stack: ");
    //     scanf("%d",&x);
    //     push(sp,x);
    // }

     pop(sp);
     peek(sp);
     stackTop(sp);
     stackBottom(sp);
    // for (i = 1; i <= sp->top + 1; i++)
    // {
    //     printf("The value at position %d is %d\n", i, peek(sp, i));
    // }

    getch();
}