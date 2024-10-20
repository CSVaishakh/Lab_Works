package com.vaishakh.lab;

public class Polymorphism {
    abstract class shape{
        abstract void no_of_sides();
    }
    class rectangle extends shape{
        void no_of_sides(){
            System.out.println("Rectangle has 4 sides");
        }
    }
    class triangle extends shape{
        void no_of_sides(){
            System.out.println("Triangle has 3 sides");
        }
    }
    class hexagon extends shape{
        void no_of_sides(){
            System.out.println("Hexagon has 6 sides");
        }
    }
}

class P_main {
    public static void main(String[] args) {
        Polymorphism ab = new Polymorphism();
        Polymorphism.shape rcc = ab.new rectangle();
        Polymorphism.shape tri = ab.new triangle();
        Polymorphism.shape hex = ab.new hexagon();
        rcc.no_of_sides();
        tri.no_of_sides();
        hex.no_of_sides();
    }
}

