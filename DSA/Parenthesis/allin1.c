#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#define MAX 100

float st[MAX];
int top = -1;

void push(float *st, float value) {
    if (top == MAX - 1)
        printf("Stack Overflow");
    else
        st[++top] = value;
}

float pop(float *st) {
    float value = -1;
    if (top == -1) {
        printf("Stack Overflow");
    } else {
        value = st[top];
        top--;
    }
    return value;
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%');
}

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/' || op == '%')
        return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i++];
        else if (infix[i] == '(')
            push(st, infix[i++]);
        else if (infix[i] == ')') {
            while (top != -1 && st[top] != '(')
                postfix[j++] = pop(st);
            pop(st); // Pop '('
            i++;
        } else {
            while (top != -1 && precedence(st[top]) >= precedence(infix[i]))
                postfix[j++] = pop(st);
            push(st, infix[i++]);
        }
    }
    while (top != -1)
        postfix[j++] = pop(st);
    postfix[j] = '\0';
}

float evaluatePostfix(char *exp) {
    int i = 0;
    int op1 = 0, op2 = 0, value = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(st, (float)(exp[i] - '0'));
        } else {
            op2 = pop(st);
            op1 = pop(st);
            switch (exp[i]) {
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

void main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression:");
    gets(infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    printf("The evaluation of postfix expression is %.1f", evaluatePostfix(postfix));
    getch();
}
