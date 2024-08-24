package com.vaishakh.lab.classes;

import java.util.Scanner;

public class method_overloading {
    public static class methods{
        int clacarea(int l, int b){
            int area = l*b;
            return area;
        }
        void calcarea(float r){
            System.out.println("Area of the circle of radius "+r+" is "+3.14*r*r);
        }
        void calcarea(float b,float h){
            System.out.println("Area of the triangle of base "+b+" and height "+h+" is "+(b*h)/2);
        }
    }
    public static void main(String[] args) {
        methods obj = new methods();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the base of the triangle");
        float base = sc.nextFloat();
        System.out.println("Enter the height of the triangle");
        float height = sc.nextFloat();

        System.out.println("Enter the radius of the circle");
        float r = sc.nextFloat();

        System.out.println("Enter the length of the rectangle");
        int l = sc.nextInt();
        System.out.println("Enter the breadth of the rectangle");
        int  b = sc.nextInt();
        int a = obj.clacarea(l,b);
        System.out.println("Area of the rectangle with length "+l+" and breadth "+b+" is "+a);
        obj.calcarea(r);
        obj.calcarea(base,height);
        sc.close();
    }
}
