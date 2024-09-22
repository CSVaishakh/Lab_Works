package com.vaishakh.lab.emp_dat;

public class officer extends employe{
    public officer(String name, int age, int emp_id, long ph_no, String address){
        super(name,age,emp_id,ph_no,address);
    }

    void display2(){
        System.out.println("The details of the officer is");
        super.display();

    }
}
