package com.vaishakh.OOPs;


public class classes {
    //creating a class
    static class student {
        String name;
        int rollno;
        double cgpa;

        //Constructor:
        student(String name, int rollno, double cgpa) {
            this.name = name;
            this.rollno = rollno;
            this.cgpa = cgpa;
        }
        //constructor overloading:
        student(){
            this.name="Jon Snow";
            this.rollno = 65;
            this.cgpa = 7.0;
        }
    }


    


    public static void main(String[] args) {
        //using constructors:
        student student1 = new student("Abhijith",1,8.5);
        System.out.println("Name : "+student1.name+"\nRoll-NO : "+student1.rollno+"\nCGPA : "+student1.cgpa);
        //constructor overloading:
        student student2 = new student();
        System.out.println("Name : "+student2.name+"\nRoll-NO : "+student2.rollno+"\nCGPA : "+student2.cgpa);
    }
}
