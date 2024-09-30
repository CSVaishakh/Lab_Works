package com.vaishakh.lab.exception_handling;

import java.util.Scanner;
public class try_catch {
    public static void main(String[] args) throws IllegalAccessException {
        Scanner sc = new Scanner(System.in);
        int age;
        System.out.print("Enter age of voter: ");
        age = sc.nextInt();
        age_verify av = new age_verify();
        av.vote(age);
        System.out.println("Verification completed successfully");
    }
}
