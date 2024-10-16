#include <stdio.h>
#include <stdlib.h>

// Structure for a term in the polynomial
struct polynomial {
    int coeff;
    int expo;
    struct polynomial* next;
};

// Function to create a new node
struct polynomial* create_node(int coeff, int expo) {
    struct polynomial* new_node = (struct polynomial*)malloc(sizeof(struct polynomial));
    new_node->coeff = coeff;
    new_node->expo = expo;
    new_node->next = NULL;
    return new_node;
}

// Function to insert a term at the end of the polynomial
void insert_term(struct polynomial** poly, int coeff, int expo) {
    struct polynomial* new_node = create_node(coeff, expo);
    if (*poly == NULL) {
        *poly = new_node;
    } else {
        struct polynomial* temp = *poly;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

// Function to read a polynomial from user input
void read_polynomial(struct polynomial** poly) {
    int n, coeff, expo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &coeff);
        printf("Enter the exponent: ");
        scanf("%d", &expo);
        insert_term(poly, coeff, expo);
    }
}

// Function to display a polynomial
void display_polynomial(struct polynomial* poly) {
    struct polynomial* temp = poly;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
struct polynomial* add_polynomials(struct polynomial* p1, struct polynomial* p2) {
    struct polynomial* result = NULL;
    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            insert_term(&result, p1->coeff, p1->expo);
            p1 = p1->next;
        } else if (p1->expo < p2->expo) {
            insert_term(&result, p2->coeff, p2->expo);
            p2 = p2->next;
        } else {
            int sum_coeff = p1->coeff + p2->coeff;
            if (sum_coeff != 0) {
                insert_term(&result, sum_coeff, p1->expo);
            }
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    // Add remaining terms from p1, if any
    while (p1 != NULL) {
        insert_term(&result, p1->coeff, p1->expo);
        p1 = p1->next;
    }

    // Add remaining terms from p2, if any
    while (p2 != NULL) {
        insert_term(&result, p2->coeff, p2->expo);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct polynomial *p1 = NULL, *p2 = NULL, *p3 = NULL;

    printf("Enter the first polynomial:\n");
    read_polynomial(&p1);

    printf("Enter the second polynomial:\n");
    read_polynomial(&p2);

    printf("\nFirst polynomial: ");
    display_polynomial(p1);

    printf("Second polynomial: ");
    display_polynomial(p2);

    p3 = add_polynomials(p1, p2);

    printf("Resultant polynomial: ");
    display_polynomial(p3);

    // Free memory (not implemented for brevity)

    return 0;
}