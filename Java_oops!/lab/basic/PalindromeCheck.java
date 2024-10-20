package com.vaishakh.lab.basic;

import java.util.Scanner;

public class PalindromeCheck {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.println("Enter the word to be checked for palindrome");
        String word = in.nextLine();
        int x = word.length();
        char[] letters=word.toCharArray();
        boolean flag = true;
        for (int i=0;i<x/2;i++) {
            if (letters[i]!=letters[x-i-1]) {
                flag = false;
                break;
            }
        }
        if(flag){
            System.out.println("The word is a palindrome");
            return;
        }
        System.out.println("The word is not a palindrome");
    }
}
