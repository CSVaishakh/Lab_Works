package com.vaishakh.lab;

abstract class Shape {
    abstract void printArea(double... sides);
}

class Rectangle extends Shape {
    @Override
    void printArea(double... sides) {
        double area = sides[0] * sides[1];
        System.out.println("Area of Rectangle: " + area);
    }
}

class Triangle extends Shape {
    @Override
    void printArea(double... sides) {
        double area = 0.5 * sides[0] * sides[1];
        System.out.println("Area of Triangle: " + area);
    }
}

class Hexagon extends Shape {
    @Override
    void printArea(double... sides ) {
        double area = ((3 * Math.sqrt(3)) / 2) * sides[0] * sides[0];
        System.out.println("Area of Hexagon: " + area);
    }
}

class ShapeAreaCalculator {
    public static void main(String[] args) {

        Shape rectangle = new Rectangle();
        Shape triangle = new Triangle();
        Shape hexagon = new Hexagon();

        rectangle.printArea(10,15);
        triangle.printArea(10,15);
        hexagon.printArea(10);
    }
}