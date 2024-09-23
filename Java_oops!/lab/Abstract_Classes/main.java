package com.vaishakh.lab.Abstract_Classes;

public class main {
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
