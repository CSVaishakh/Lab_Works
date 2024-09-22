package com.vaishakh.lab.emp_dat;

class manager extends employe{
    public manager(String name,int age,int emp_id,long ph_no,String address){
        super(name,age,emp_id,ph_no,address);
    }

    void display1(){
        System.out.println("The details of the manager is");
        super.display();

    }
}
