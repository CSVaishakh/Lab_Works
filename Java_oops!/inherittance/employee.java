package com.vaishakh.inheriitance.lab;

public class employee {
    static  int Base_Sal;
    static int TA;
    static int DA;

    public employee(int base_Sal, int TA, int DA) {
        this.Base_Sal = base_Sal;
        this.TA = TA;
        this.DA = DA;
    }

    void display(){
        System.out.println("name od the class is Employee");
    }

    void calc_salary(){
        int Gross_Sal= Base_Sal+TA+DA;
        System.out.println("Total salary of the employee is "+Gross_Sal);
    }

}

