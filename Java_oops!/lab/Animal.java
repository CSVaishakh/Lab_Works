package com.vaishakh.lab;

interface Pet {
    void setName(String name);
    String getName();
    void play();
}
class Animal {
    private String name;
    private int legs;
    Animal(int legs) {
        this.legs = legs;
    }
    void walk() {
        System.out.println("This animal walks on " + legs + " legs");
    }
    void eat() {
        System.out.println("This animal eats");
    }
}
class Dog extends Animal implements Pet {
    private String name;
    Dog(int legs, String name) {
        super(legs);
        this.name = name;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void play() {
        System.out.println("Dogs love to play with balls");
    }
    @Override
    public void eat() {
        System.out.println("Dogs eat meat and veggies");
    }
}
class Main {
    public static void main(String[] args) {
        Dog myDog = new Dog(4, "Buddy");
        myDog.walk();
        myDog.eat();
        myDog.play();
        System.out.println("Dog's name: " + myDog.getName());
    }
}