#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

struct Node *createNode(int coef, int exp) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}
struct node *createPolynomial()
{
    struct node *poly=NULL;
    int coef,exp;

    while(1)
    {
        printf("\nEnter the coefficient:");
        scanf("%d ",&coef);
        printf("\nEnter the exponent:");
        scanf("%d",&exp);
        if(coef==-1 && exp==-1)
        {
            break;
        }
        poly=insertTerm(poly,coef,exp);
    }
    return poly;
}
struct Node *insertTerm(struct Node *poly, int coef, int exp) {
    struct Node *newNode = createNode(coef, exp);
    if (poly == NULL) {
        return newNode;
    } else {
        struct Node *temp = poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        return poly;
    }
}

struct Node *operatePolynomials(struct Node *poly1, struct Node *poly2, char operation) {
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    struct Node *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        int coef = (operation == '+') ? temp1->coefficient + temp2->coefficient : temp1->coefficient - temp2->coefficient;
        result = insertTerm(result, coef, temp1->exponent);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != NULL) {
        result = insertTerm(result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        int coef = (operation == '+') ? temp2->coefficient : -temp2->coefficient;
        result = insertTerm(result, coef, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

void displayPolynomial(struct Node *poly) {
    struct Node *temp = poly;
    while (temp != NULL) {
        printf("%c %dx^%d ", (temp == poly) ? '\0' : (temp->coefficient < 0) ? '-' : '+', abs(temp->coefficient), temp->exponent);
        temp = temp->next;
    }
    printf("\n");
}

void freePolynomial(struct Node *poly) {
    struct Node *temp;
    while (poly != NULL) {
        temp = poly;
        poly = poly->next;
        free(temp);
    }
}

int main() {
    struct Node *poly1 = NULL, *poly2 = NULL;
    int choice;

    do {
        printf("\nMain Menu:\n1. Enter polynomial 1\n2. Enter polynomial 2\n3. Add polynomials\n4. Subtract polynomials\n5. Display polynomials\n-1. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                poly1 = createPolynomial();
                break;
            case 2:
                poly2 = createPolynomial();
                break;
            case 3:
                printf("Sum: ");
                displayPolynomial(operatePolynomials(poly1, poly2, '+'));
                break;
            case 4:
                printf("Difference: ");
                displayPolynomial(operatePolynomials(poly1, poly2, '-'));
                break;
            case 5:
                printf("Polynomial 1: ");
                displayPolynomial(poly1);
                printf("Polynomial 2: ");
                displayPolynomial(poly2);
                break;
            case -1:
                printf("Exiting program\n");
                exit(1);

            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != -1);

    freePolynomial(poly1);
    freePolynomial(poly2);

    return 0;
}
