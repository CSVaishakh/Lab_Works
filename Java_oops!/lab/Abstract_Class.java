package com.vaishakh.lab;

abstract class Shape {
    abstract void printArea(double side);
}

class Rectangle extends Shape {
    @Override
    void printArea(double side) {
        double area = side * side;
        System.out.println("Area of Rectangle: " + area);
    }
}

class Triangle extends Shape {
    @Override
    void printArea(double side) {
        double area = (Math.sqrt(3) / 4) * side * side;
        System.out.println("Area of Triangle: " + area);
    }
}

class Hexagon extends Shape {
    @Override
    void printArea(double side) {
        double area = ((3 * Math.sqrt(3)) / 2) * side * side;
        System.out.println("Area of Hexagon: " + area);
    }
}

class ShapeAreaCalculator {
    public static void main(String[] args) {
        double side = 5.0; // You can change this value to test different side lengths

        Shape rectangle = new Rectangle();
        Shape triangle = new Triangle();
        Shape hexagon = new Hexagon();

        rectangle.printArea(side);
        triangle.printArea(side);
        hexagon.printArea(side);
    }
}