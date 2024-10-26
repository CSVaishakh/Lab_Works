package com.vaishakh.lab;

import java.util.StringTokenizer; // Import the correct StringTokenizer class
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class String_Tokenizer { // Renamed class to avoid conflict
    public static void main(String[] args) {
        // Create a BufferedReader object to read user input
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        try {
            // Prompt the user to enter numbers separated by space
            System.out.print("Enter the numbers separated by space: ");
            String input = reader.readLine(); // Read user input

            // Create StringTokenizer object
            StringTokenizer tokenizer = new StringTokenizer(input);

            int sum = 0; // Initialize sum

            // Display each integer and calculate the sum
            System.out.println("Numbers are:");
            while (tokenizer.hasMoreTokens()) {
                String token = tokenizer.nextToken(); // Get next token
                int number = Integer.parseInt(token); // Convert token to integer
                System.out.println(number); // Display the integer
                sum += number; // Add integer to sum
            }

            // Display the sum after processing all numbers
            System.out.println("Sum = " + sum);

            // Close the BufferedReader
            reader.close();

        } catch (IOException e) {
            System.err.println("Error reading input: " + e.getMessage());
        } catch (NumberFormatException e) {
            System.err.println("Invalid input. Please enter integers separated by space.");
        }
    }
}