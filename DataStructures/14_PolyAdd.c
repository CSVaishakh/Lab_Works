#include <stdio.h>
#include <stdlib.h>
// Structure to represent a term in the polynomial
// Each term has a coefficient, exponent, and a pointer to the next term
struct polynomial {
    int coeff;  // Coefficient of the term
    int expo;   // Exponent of the term
    struct polynomial* next;  // Pointer to the next term in the polynomial
};
// Function to create a new node (term) for the polynomial
struct polynomial* create_node(int coeff, int expo) {
    // Allocate memory for a new node
    struct polynomial* new_node = (struct polynomial*)malloc(sizeof(struct polynomial));
    // Initialize the node with given coefficient and exponent
    new_node->coeff = coeff;
    new_node->expo = expo;
    new_node->next = NULL;  // Set next pointer to NULL (end of list for now)
    return new_node;
}
// Function to insert a term at the end of the polynomial
void insert_term(struct polynomial** poly, int coeff, int expo) {
    // Create a new node with given coefficient and exponent
    struct polynomial* new_node = create_node(coeff, expo);
    // If the polynomial is empty, make the new node the first term
    if (*poly == NULL) {
        *poly = new_node;
    } else {
        // Otherwise, traverse to the end of the list and add the new node
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
    // Read n terms from the user
    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &coeff);
        printf("Enter the exponent: ");
        scanf("%d", &expo);
        // Insert each term into the polynomial
        insert_term(poly, coeff, expo);
    }
}
// Function to display a polynomial
void display_polynomial(struct polynomial* poly) {
    struct polynomial* temp = poly;
    // Traverse the linked list and print each term
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->expo);
        temp = temp->next;
        // Print '+' between terms, except for the last term
        if (temp != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}
// Function to add two polynomials
struct polynomial* add_polynomials(struct polynomial* p1, struct polynomial* p2) {
    struct polynomial* result = NULL;
    // Traverse both polynomials simultaneously
    while (p1 != NULL && p2 != NULL) {
        if (p1->expo > p2->expo) {
            // If p1's exponent is higher, add its term to the result
            insert_term(&result, p1->coeff, p1->expo);
            p1 = p1->next;
        } else if (p1->expo < p2->expo) {
            // If p2's exponent is higher, add its term to the result
            insert_term(&result, p2->coeff, p2->expo);
            p2 = p2->next;
        } else {
            // If exponents are equal, add coefficients
            int sum_coeff = p1->coeff + p2->coeff;
            if (sum_coeff != 0) {
                // Only add the term if the sum of coefficients is not zero
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
    // Read the first polynomial
    printf("Enter the first polynomial:\n");
    read_polynomial(&p1);
    // Read the second polynomial
    printf("Enter the second polynomial:\n");
    read_polynomial(&p2);
    // Display both polynomials
    printf("\nFirst polynomial: ");
    display_polynomial(p1);
    printf("Second polynomial: ");
    display_polynomial(p2);
    // Add the polynomials
    p3 = add_polynomials(p1, p2);
    // Display the result
    printf("Resultant polynomial: ");
    display_polynomial(p3);
    return 0;
}