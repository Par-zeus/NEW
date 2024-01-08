#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define MAX 100
float st[MAX];
int top = -1;
void push(float *st, float value)
{
    if (top == MAX - 1)
        printf("Stack Overflow");
    else
    {
        // top++;
        st[++top] = value;
    }
}
float pop(float *st)
{
    float value = -1;
    if (top == -1)
    {
        printf("Stack Overflow");
    }
    else
    {
        value = st[top];
        top--;
    }
    return value;
}
float evaluatePostfix(char *exp)
{
    int i = 0;
    int op1 = 0, op2 = 0, value = 0;
    while (exp[i] != '\0')
    {
        if (isdigit(exp[i]))
        {
            push(st, (float)(exp[i] - '0'));
        }
        else
        {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i])
            {
            case '+':
                value = op1 + op2;
                break;
            case '-':
                value = op1 - op2;
                break;
            case '*':
                value = op1 * op2;
                break;
            case '/':
                value = op1 / op2;
                break;
            case '%':
                value = (int)op1 % (int)op2;
                break;
            }
            push(st, value);
        }
        i++;
    }
    return pop(st);
}
void main()
{
    char exp[100];
    printf("Enter postfix expression:");
    gets(exp);
    printf("The evaluation of postfix expression is %.1f", evaluatePostfix(exp));
    getch();
}
