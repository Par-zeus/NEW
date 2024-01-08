#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a term in the polynomial
struct Node {
    int coefficient;
    int exponent;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int coef, int exp) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coefficient = coef;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into a polynomial
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

// Function to create a polynomial based on user input
// Function to create a polynomial based on user input
struct Node *createPolynomial() {
    struct Node *poly = NULL;
    int coef, exp;

    while (1) {
        printf("Enter the coefficient: ");
        scanf("%d", &coef);

        printf("Enter the exponent: ");
        scanf("%d", &exp);

        if (coef == -1 && exp == -1) {
            break;
        }

        poly = insertTerm(poly, coef, exp);
    }

    return poly;
}


// Function to add two polynomials
struct Node *addPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    struct Node *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            result = insertTerm(result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            result = insertTerm(result, temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            // Exponents are equal, add coefficients
            result = insertTerm(result, temp1->coefficient + temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Copy the remaining terms from poly1, if any
    while (temp1 != NULL) {
        result = insertTerm(result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    // Copy the remaining terms from poly2, if any
    while (temp2 != NULL) {
        result = insertTerm(result, temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

// Function to subtract one polynomial from another
struct Node *subtractPolynomials(struct Node *poly1, struct Node *poly2) {
    struct Node *result = NULL;
    struct Node *temp1 = poly1;
    struct Node *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exponent > temp2->exponent) {
            result = insertTerm(result, temp1->coefficient, temp1->exponent);
            temp1 = temp1->next;
        } else if (temp1->exponent < temp2->exponent) {
            result = insertTerm(result, -temp2->coefficient, temp2->exponent);
            temp2 = temp2->next;
        } else {
            // Exponents are equal, subtract coefficients
            result = insertTerm(result, temp1->coefficient - temp2->coefficient, temp1->exponent);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    // Copy the remaining terms from poly1, if any
    while (temp1 != NULL) {
        result = insertTerm(result, temp1->coefficient, temp1->exponent);
        temp1 = temp1->next;
    }

    // Copy the remaining terms from poly2 with negation, if any
    while (temp2 != NULL) {
        result = insertTerm(result, -temp2->coefficient, temp2->exponent);
        temp2 = temp2->next;
    }

    return result;
}

// Function to display a polynomial
void displayPolynomial(struct Node *poly, char operation) {
    struct Node *temp = poly;
    while (temp != NULL) {
        if (temp->coefficient > 0 && temp != poly) {
            printf(" + ");
        }
        if (temp->coefficient < 0) {
            printf(" - ");
        }
        printf("%dx^%d", abs(temp->coefficient), temp->exponent);
        temp = temp->next;
    }
    printf("\n");
}

// Function to free memory allocated for a polynomial
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
        printf("\nMenu:\n");
        printf("1. Enter polynomial 1\n");
        printf("2. Enter polynomial 2\n");
        printf("3. Add polynomials\n");
        printf("4. Subtract polynomials\n");
        printf("5. Display polynomials\n");
        printf("6. Exit\n");
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
                displayPolynomial(addPolynomials(poly1, poly2), '+');
                break;
            case 4:
                printf("Difference: ");
                displayPolynomial(subtractPolynomials(poly1, poly2), '-');
                break;
            case 5:
                printf("Polynomial 1: ");
                displayPolynomial(poly1, ' ');
                printf("Polynomial 2: ");
                displayPolynomial(poly2, ' ');
                break;
            case 6:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    } while (choice != 6);

    // Free memory
    freePolynomial(poly1);
    freePolynomial(poly2);

    return 0;
}
