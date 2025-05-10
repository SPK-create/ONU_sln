#include <iostream>
#include "Animal.h"

int main() {
    Dog d("Fido", 3);
    Cat c("Fluffy", 5);
    Dog d1("Barky", 3);

    Mammal* arr[] = { &d, &c, &d1 };
    
    // should woof, meow, woof
    for (int i = 0; i < 3; i++) {
        arr[i]->makeSound();
    }

    // should eat in dog, cat, dog order
    for (int i = 0; i < 3; i++) {
        arr[i]->eat();
    }

    // should woof, meow, woof
    for (int i = 0; i < 3; i++) {
        arr[i]->makeSound();
    }

    // should sleep in dog, cat, dog order
    for (int i = 0; i < 3; i++) {
        arr[i]->sleep();
    }

    // shoudn't do anything as they're sleeping
    for (int i = 0; i < 3; i++) {
        arr[i]->makeSound();
    }

    // shoudn't eat actually, as they are sleeping
    for (int i = 0; i < 3; i++) {
        arr[i]->eat();
    }


    //!!!!!!!!! CAN`T BE USED BECAUSE ALL CLASSES EXCEPT DOG !!!!!!!!!!!
    /*//shouldn't wag tails, they are sleeping, but some of them do not wag tail at all
    for (int i = 0; i < 3; i++) {
        arr[i]->wagTail();
    }*/

    // do they really need to sleep forever? :'(

    // Hah, that's stange :)
    /*Tail t("Taily", 2);
    t.makeSound();*/
}