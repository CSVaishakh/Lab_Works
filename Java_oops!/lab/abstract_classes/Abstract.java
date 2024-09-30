package com.vaishakh.lab.abstract_classes;

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
