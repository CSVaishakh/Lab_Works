package com.vaishakh.lab;

import java.util.Scanner;

public class emp{
    static  int Base_Sal;
    static int TA;
    static int DA;
    public emp(int base_Sal, int TA, int DA) {
        Base_Sal = base_Sal;
        emp.TA = TA;
        emp.DA = DA;
    }
    void display(){
        System.out.println("name od the class is Employee");
    }

    void calc_salary(){
        int Gross_Sal= Base_Sal+TA+DA;
        System.out.println("Total salary of the employee is "+Gross_Sal);
    }
}

class empengineer extends emp {
    public empengineer(int base_Sal, int TA, int DA) {
        super(base_Sal, TA, DA);
    }

    @Override
    void display() {
        super.display();
        System.out.println("Name of the class is Engineer");
    }

    @Override
    void calc_salary() {
        super.calc_salary();
        System.out.println("Total salary of the engineer " + " is " + 2 * (Base_Sal + TA + DA));
    }
}
class empmain {
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