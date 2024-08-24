package com.vaishakh.lab.basic;

import java.util.Scanner;
public class fib {
    public static void main(String[] args) {
        int i;
        int t1=0;
        int t2=1;
        int nxt=t1+t2;
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the value of n");
        int n=in.nextInt();
        System.out.println("the fibonacci series is");
        System.out.print(t1+" "+t2);
        for(i=3;i<=n;i++){
            System.out.print(" "+nxt);
            t1=t2;
            t2=nxt;
            nxt=t1+t2;
        }
    }
}
