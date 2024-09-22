package com.vaishakh.lab.basic;

import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the word to be checked for palindrome");
        String word = in.nextLine();
        int x = word.length();
        char[] letters=word.toCharArray();
        for (int i=0;i<=x;i++) {
            if (letters[i]==letters[x-i-1]){
                System.out.println(word+ " is a palindrome");
                break;
            }
            else {
                System.out.println(word+ " is not a palindrome");
                break;
            }
        }
    }
}
