package com.vaishakh.lab.exception_handling;

public class age_verify {
        void vote(int age) throws IllegalAccessException {
            for (int i = 0; i <10; i++){
                try {
                    if (age<18) {
                        throw new IllegalAccessException("You must be at least 18 years to vote");
                    }
                    else{
                        System.out.println("You can vote!");

                    }
                } catch (Exception e){
                    System.out.println("Exception Occurred: "+e);
                } finally {
                    System.out.println("Finally age verification done");
                }
                break;
            }
        }
}
