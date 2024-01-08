#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//  if a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

//  precedence of an operator
int precedence(char op)
{
    if (op == '^')
        return 3; // highest precedence
    else if (op == '*' || op == '/' || op == '%')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0; // lowest precedence
}

//  if a character is an operand (a digit or a letter)
int isOperand(char ch)
{
    return isalnum(ch);
}

void infixToPostfix(char *infix, char *postfix)
{
    char stack[100];
    int top = -1;
    int j = 0; // Track postfix addition

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (ch == ' ' || ch == '\t')
        {
            continue; // Skip spaces and tabs
        }
        else if (isOperand(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top >= 0 && stack[top] != '(')
            {
                postfix[j++] = stack[top--];
            }
            // to remove the parenthesis
            if (top >= 0 && stack[top] == '(')
            {
                top--;
            }
        }
        else if (isOperator(ch))
        {
            while (top >= 0 && precedence(stack[top]) >= precedence(ch))
            {
                postfix[j++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }

    while (top >= 0)
    {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';
}

void infixToPrefix(char *infix, char *prefix)
{
    char reversedInfix[100];
    int j = 0;

   
    for (int i = strlen(infix) - 1; i >= 0; i--)
    {
        if (infix[i] == '(')
            reversedInfix[j++] = ')';
        else if (infix[i] == ')')
            reversedInfix[j++] = '(';
        else
            reversedInfix[j++] = infix[i];
    }
    reversedInfix[j] = '\0';

    // Convert the reversed infix expression to postfix
    char postfix[100];
    infixToPostfix(reversedInfix, postfix);

    // Reverse the postfix expression to obtain the prefix
    j = 0;
    for (int i = strlen(postfix) - 1; i >= 0; i--)
    {
        prefix[j++] = postfix[i];
    }
    prefix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100], prefix[100];
    printf("Enter an infix expression: ");
    gets(infix);

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    printf("Postfix: %s\n", postfix);
    printf("Prefix: %s\n", prefix);

    return 0;
}
