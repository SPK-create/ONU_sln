#ifndef ANIMAL_H
#define ANIMAL_H //Change letter O with A

#include <string>

class Animal {
protected:
	std::string name;
	int age;

public:
	Animal(std::string n, int a);
	virtual void makeSound();
	//Added tag virtual to eat function
	virtual void eat();
	virtual void sleep();
};

class Mammal : protected Animal {
protected:
	bool isSleeping;

public:
	Mammal(std::string n, int a);
	//Added tag virtual to makeSound, eat and sleep functions
	virtual void makeSound();
	virtual void eat();
	virtual void sleep();
};

//Upper then class Dog for usage it there
class Tail {
public:
	//Changed constructor of Tail to default mode
	Tail();
};

class Dog : public Mammal {
private:
	bool isTailWagging;
	//added a Tail variable
	Tail tail;
public:
	Dog(std::string n, int a);
	void makeSound();
	void eat();
	void sleep();
	void fetch();
	void wagTail();
};

class Cat : public Mammal {
private:
	int numberOfLives;

public:
	Cat(std::string n, int a);
	void makeSound();
	void eat();
	void sleep();
};

#endif