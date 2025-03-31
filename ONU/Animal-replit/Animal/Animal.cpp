#include "Animal.h"
//#include <Animality> Nonexisting module
#include <iostream>

Animal::Animal(std::string n, int a) {
    name = n;
    age = a;
}

void Animal::makeSound() {
    std::cout << "This is a generic animal sound." << std::endl;
}

void Animal::eat() { std::cout << "The animal is eating." << std::endl; }

void Animal::sleep() { std::cout << "The animal is sleeping." << std::endl; }

//Added age parametr 
Mammal::Mammal(std::string n, int a): Animal(n, a) { isSleeping = false; }

//Added a check whether mammal is sleeping
void Mammal::makeSound() {
    if (isSleeping) {
        std::cout << "Zzz" << std::endl;
    }
    else {
        std::cout << "This is a generic mammal sound." << std::endl;
    }
}
//Added a check whether mammal is sleeping
void Mammal::eat() { 
    if (isSleeping) {
        std::cout << "Zzz" << std::endl;
    }
    else {
        std::cout << "The mammal is eating." << std::endl;
    }
}

void Mammal::sleep() {
    std::cout << "The mammal is sleeping." << std::endl;
    //isSleeping = true;
    isSleeping = true;
}

Dog::Dog(std::string n, int a): Mammal(n, a) { isTailWagging = false; }

//Added a check whether dog is sleeping
void Dog::makeSound() {   
    if (isSleeping) {
        std::cout << "Zzz" << std::endl;
    }
    else {
        std::cout << "Woof!" << std::endl;
    }
}

//Added a check whether dog is sleeping
void Dog::eat() { 
    if (isSleeping) {
        std::cout << "Zzz" << std::endl;
    }
    else {
        std::cout << "The dog is eating." << std::endl;
    }
}

void Dog::sleep() {
    std::cout << "The dog is sleeping." << std::endl;
    //isSleeping = true;
    isSleeping = true;
}

void Dog::fetch() { std::cout << "The dog is fetching." << std::endl; }

void Dog::wagTail() {
    if (isSleeping == true) {
        std::cout << "The dog can't wag its tail because it's sleeping."
            << std::endl;
    }
    else {
        std::cout << "The dog is wagging its tail." << std::endl;
        isTailWagging = true;
    }
}

Cat::Cat(std::string n, int a): Mammal(n, a) { numberOfLives = 9; }

//Added a check whether cat is sleeping
void Cat::makeSound() { 
    if (isSleeping) {
        std::cout << "Zzz" << std::endl;
    }
    else {
        std::cout << "Meow!" << std::endl;
    }
}

//Added a check whether cat is sleeping
void Cat::eat() { 
    if (isSleeping) {
        std::cout << "Zzz" << std::endl;
    }
    else {
        std::cout << "The cat is eating." << std::endl;
    }
}

void Cat::sleep() {
    std::cout << "The cat is sleeping." << std::endl;
    isSleeping = true;
}

Tail::Tail() {}

//int Cat::eat = eat(); !!!!!!