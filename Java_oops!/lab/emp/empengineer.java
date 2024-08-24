package com.vaishakh.lab.emp;

public class empengineer extends emp{
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
        System.out.println("Total salary of the engineer "+" is "+2*(Base_Sal+TA+DA));
    }
}
