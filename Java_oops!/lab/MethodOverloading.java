

import java.util.Scanner;

public class MethodOverloading {
    public static class methods{
        int calc_area(int l, int b){
            return l*b;
        }
        double calc_area(float r){
            return 3.14*r*r;
        }
        void calc_area(float b,float h){
            System.out.println("Area of the triangle is "+(b*h)/2);
        }
    }
    public static void main(String[] args) {
        methods obj = new methods();
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the length and breadth of the rectangle");
        int l = sc.nextInt();
        int  b = sc.nextInt();
        System.out.println("Enter the height and base of the triangle");
        float base = sc.nextFloat();
        float height = sc.nextFloat();
        System.out.println("Enter the radius of the circle");
        float r = sc.nextFloat();
        System.out.println("Area of the rectangle is "+obj.calc_area(l,b));
        obj.calc_area(base,height);
        System.out.println("Area of the circle is "+obj.calc_area(r));
        sc.close();
    }
}
