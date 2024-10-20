package com.vaishakh.lab.basic;

import java.util.Scanner;

public class FrequencyCounter {
    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String str = in.nextLine();
        System.out.println("Enter the letter");
        String chs = in.next();
        char[] chars = str.toCharArray();
        char ch=chs.charAt(0);
        int i,count=0;
        int len=str.length();
        for(i=0;i<len;i++){
            if(ch==chars[i]){
                count++;
            }
        }
        System.out.println();
        System.out.println(ch+" repeats "+count+" times");
    }
}
