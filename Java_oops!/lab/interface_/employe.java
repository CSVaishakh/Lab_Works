package com.vaishakh.lab.interface_;

public class employe {
    static String name = "";
    static int age = 0;
    static int emp_id = 0;
    static long ph_no = 0;
   static String address = "";

    public employe(String name,int age,int emp_id,long ph_no,String address){
        this.name = name;
        this.age = age;
        this.emp_id = emp_id;
        this.ph_no = ph_no;
        this.address = address;

    }

    void display(){
        System.out.println(name+"\n"+age+"\n"+emp_id+"\n"+ph_no+"\n"+address);
    }
}
