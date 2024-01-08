
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
// #include <ctype.h>
// "(" -> if yes then push into the stack
// ")" -> if yes then pop into the stack

struct stack
{
    int size;
    int top;
    char *arr; // use to dynamically allocate memeory
};

// push():adds element at thr top of stack
char push(struct stack *sp, char value)
{
    if (sp->top == sp->size - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = value;
    }
}
// pop():remove the top element from the stack
char pop(struct stack *sp)
{
    if (sp->top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char value = sp->arr[sp->top];
        sp->top--;
        return value;
        // printf("Popped %d from stack\n", value);
    }
}
int precedence(char ch)
{
    if (ch == '*' || ch == '/' || ch == '%')
        return 3; // highest precedence
    else if (ch == '+' || ch == '-')
        return 2; // second highest precedence
    else
        return 0;
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '%' || ch == '/')
        return 1;
    else
        return 0;
}
int stackTop(struct stack *sp)
{
    return sp->arr[sp->top];
}
char *infixtopostfix(char *infix, char *postfix)
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    //char *postfix = (char *)malloc((strlen(infix + 1)) * sizeof(char));
    int i = 0; // track infix traversal
    int j = 0; // track postfix addition

    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i])) // i.e if operand hai toh postfix expression mei daldo
        // if(isdigit(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else
            {
                postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (sp->top != -1) // jab tkh value null nhi hoa tbh tkh sab operator pop krdo postfix mei
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

void main()
{
    char infix[100],postfix[100];
    printf("Enter the expression: ");
    gets(infix);
    // printf("Postfix is %s\n", infixtopostfix(infix));
    printf("The postfix is: ");
    infixtopostfix(infix,postfix);
    printf("The postfix is:");
    puts(postfix);
    // char *exp=infixtopostfix(infix);
    // puts(exp);
    getch();
}
