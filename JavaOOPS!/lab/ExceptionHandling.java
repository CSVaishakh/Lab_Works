

import java.util.Scanner;

class age_verify {
    void vote(int age) {
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
    }
}

class try_catch {
    public static void main(String[] args) throws IllegalAccessException {
        Scanner sc = new Scanner(System.in);
        int age;
        System.out.print("Enter age of voter: ");
        age = sc.nextInt();
        age_verify av = new age_verify();
        av.vote(age);
        System.out.println("Verification completed successfully");
        sc.close();
    }
}
