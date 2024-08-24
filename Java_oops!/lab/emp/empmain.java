package com.vaishakh.lab.emp;

import java.util.Scanner;

public class empmain {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int base_Sal, TA, DA;
        System.out.println("Enter the base_Sal: ");
        base_Sal = sc.nextInt();
        System.out.println("Enter the TA: ");
        TA = sc.nextInt();
        System.out.println("Enter the DA: ");
        DA = sc.nextInt();
        empengineer engineer1 = new empengineer(base_Sal, TA, DA);

        engineer1.calc_salary();
        engineer1.display();
    }
}
