package com.vaishakh.lab;

class Employee {
    String name;
    int age;
    String phoneNumber;
    String address;
    double salary;

    Employee(String name, int age, String phoneNumber, String address, double salary) {
        this.name = name;
        this.age = age;
        this.phoneNumber = phoneNumber;
        this.address = address;
        this.salary = salary;
    }
    void printSalary() {
        System.out.println("Salary: $" + salary);
    }
    void printDetails() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Phone Number: " + phoneNumber);
        System.out.println("Address: " + address);
        printSalary();
    }
}

class Officer extends Employee {
    String specialization;

    Officer(String name, int age, String phoneNumber, String address, double salary, String specialization) {
        super(name, age, phoneNumber, address, salary);
        this.specialization = specialization;
    }

    void printDetails() {
        super.printDetails();
        System.out.println("Specialization: " + specialization);
    }
}

class Manager extends Employee {
    String department;

    Manager(String name, int age, String phoneNumber, String address, double salary, String department) {
        super(name, age, phoneNumber, address, salary);
        this.department = department;
    }

    void printDetails() {
        super.printDetails();
        System.out.println("Department: " + department);
    }
}

class EmployeeManagementSystem {
    public static void main(String[] args) {
        Officer officer = new Officer("John Doe", 30, "1234567890", "123 Main St, MANCHESTER City", 75000, "Cybersecurity");
        Manager manager = new Manager("Jane Smith", 35, "9876543210", "456 Elm St, MANCHESTER City", 90000, "IT");

        System.out.println("Officer Details:");
        officer.printDetails();
        System.out.println("\nManager Details:");
        manager.printDetails();
    }
}
