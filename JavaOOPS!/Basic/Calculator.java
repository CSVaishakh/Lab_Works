package com.vaishakh.Basic;

import java.util.Scanner;

public class Calculator {
    public static Scanner in = new Scanner(System.in);
    public static int add(int a, int b) {
        int sum;
        sum = a + b;
        return sum;
    }
    public static int subtract(int a, int b) {
        int difference;
        difference = a - b;
        return difference;
    }
    public static int multiply(int a, int b) {
        int product;
        product = a * b;
        return product;
    }
    public static int division(int a, int b) {
        int quotient;
        quotient = a / b;
        return quotient;
    }

    public static void main(String[] args) {
        System.out.println("  CALCULATOR  ");
        System.out.println("Choose the operation to be performed");
        System.out.println("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
        System.out.print("Enter your choice: ");
        int choice = in.nextInt();
        int num1, num2;
        System.out.println("Enter the first number");
        num1 = in.nextInt();
        System.out.println("Enter the second number");
        num2 = in.nextInt();
        switch (choice) {
            case 1 -> System.out.println("The sum is " + add(num1, num2));
            case 2 -> System.out.println("The difference is " + subtract(num1, num2));
            case 3 -> System.out.println("The product is " + multiply(num1, num2));
            case 4 -> System.out.println("The quotient is " + division(num1, num2));
        }
    }
}