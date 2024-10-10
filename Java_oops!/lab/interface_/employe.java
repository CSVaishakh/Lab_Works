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

class manager extends employe {
    public manager(String name, int age, int emp_id, long ph_no, String address) {
        super(name, age, emp_id, ph_no, address);
    }

    void display1() {
        System.out.println("The details of the manager is");
        super.display();

    }
}

class officer extends employe{
    public officer(String name, int age, int emp_id, long ph_no, String address){
        super(name,age,emp_id,ph_no,address);
    }

    void display2(){
        System.out.println("The details of the officer is");
        super.display();

    }
}

interface main {
    public static void main(String[] args) {
        officer o1 = new officer("Jithin",24,102,949578656,"h1,skyline");
        o1.display2();
        manager m1 = new manager("jithu",36,101,468956712,"d2,highrise");
        m1.display1();
    }
}
