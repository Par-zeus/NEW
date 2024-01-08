#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isoperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}
int precedence(char op)
{
    if (op == '%' || op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
int isOperand(char ch)
{
    return isalnum(ch);
}

void infixtopostfix(char *infix, char *postfix)
{
    char stack[100];
    int top = -1;
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];
        if (ch == ' ' || ch == '\t')
        {
            continue;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (isOperand(ch)) // push operands into the postfix expression
        {
            postfix[j++] = ch;
        }
        else if (isoperator(ch))
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }

            if (top >= 0 && stack[top] == '(')
                top--;
        }
    }

    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}
void infixtoprefix(char *infix, char *prefix)
{
    char reverse[100];
    int j=0;

    for(int i=strlen(infix)-1;i>=0;i--)
    {
        if(infix[i]=='(')
        {
            reverse[j++]=')';
        }
       else if(infix[i]==')')
        {
            reverse[j++]='(';
        }
        else{
            reverse[j++]=infix[i];
        }
    }
    reverse[j]='\0';

    // reverse vle infix ka postfix nikala
    char postfix[100];
    infixtopostfix(reverse,postfix);
    int k=0;
    // uss postfix ka vpas reverse krke prefix nikala
    for (int i=strlen(postfix)-1;i>=0;i--)
    {
        prefix[k++]=postfix[i];
    }
    prefix[k]='\0';
}

float eval(char *exp)
{
    float stack[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];
        if (isdigit(ch))
        {
            stack[++top] = (float)(ch - '0');
        }
        else if (isoperator(ch))
        {
            // 2 num/operand ko pop krke operation perform krke result vpas push
            float operand2 = stack[top--];
            float operand1 = stack[top--];

            switch (ch)
            {
            case '+':
                stack[++top] = operand1 + operand2;
                break;
            case '-':
                stack[++top] = operand1 - operand2;
                break;
            case '*':
                stack[++top] = operand1 * operand2;
                break;
            case '/':
                stack[++top] = operand1 / operand2;
                break;
            case '%':
                stack[++top] = (int)operand1 % (int)operand2; // Modulo operation only makes sense for integers
                break;
            }
        }
    }

    return stack[top];
}
int main()
{
    char infix[100], postfix[100], prefix[100];
    printf("Enter infix expression:");
    gets(infix);

    infixtopostfix(infix, postfix);
    infixtoprefix(infix,prefix);

    printf("Postfix :%s\n", postfix);

    printf("\nevaluation is: %.1f",eval(postfix));
    printf("\nPrefix :%s ",prefix);

    return 0;
}

