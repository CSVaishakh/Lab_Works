package com.vaishakh.lab;

public class Abstract {
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

class main {
    public static void main(String[] args) {
        Abstract ab = new Abstract();
        Abstract.shape rcc = ab.new rectangle();
        Abstract.shape tri = ab.new triangle();
        Abstract.shape hex = ab.new hexagon();
        rcc.no_of_sides();
        tri.no_of_sides();
        hex.no_of_sides();
    }
}

