#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include<string.h>

int top = -1;
int stack[100]; // Declare the stack globally.

int is_operator(char op) {
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

int pop() {
    int x = stack[top];
    top--;
    return x;
}

void posteval(char s[]) {
    int i = 0;
    int j = 0;
    int result = 0;
    char element;

    while (s[i] != '\0') {
        element = s[i];
        if (isdigit(element)) {
            stack[++top] = element - '0';
        } else if (is_operator(element)) {
            int operand2 = pop();
            int operand1 = pop();
            
            switch (element) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            stack[++top] = result;
        }
        i++;
    }
    printf("Result: %d\n", stack[top]);
}

int main() {
    char s[100];
    printf("Enter a postfix expression: ");
    scanf("%s", s);
    posteval(s);
    return 0;
}