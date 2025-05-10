#include <iostream>
using namespace std;

class Engine {
private:
	float power; //Мощность
public:
	Engine() : power(0) {};
	Engine(float c) : power(c) {};
	void setPower(const float c) {
		power = c;
	}
	float getPower() {
		return power;
	}
};

class Vehicle {
protected:
	Engine engine;
	float maxSpeed;
public:
	Vehicle() : engine(), maxSpeed(0) {};
	Vehicle(Engine& engine, float maxSpeed) : engine(engine.getPower()), maxSpeed(maxSpeed) {};
	virtual string getType() {
		return "Unknown";
	}
	virtual void getInfo() = 0;
};

class Car : public Vehicle {
private:
	int numberOfSeats;
public:
	Car() : Vehicle(), numberOfSeats(0) {};
	Car(Engine& engine, float maxSpeed, int numberOfSeats) : Vehicle(engine, maxSpeed), numberOfSeats(numberOfSeats) {};
	string getType() {
		return "Car";
	}
	void getInfo() {
		cout << getType() << ":" << endl;
		cout << "Power of engine: " << engine.getPower() << "hp" << endl;
		cout << "Maximum speed: " << maxSpeed << "km/h" << endl;
		cout << "Number of seats: " << numberOfSeats << endl;
	}
};

class Truck : public Vehicle {
private:
	float cargoCapacity;
public:
	Truck() : Vehicle(), cargoCapacity(0) {};
	Truck(Engine& engine, float maxSpeed, float cargoCapacity) : Vehicle(engine, maxSpeed), cargoCapacity(cargoCapacity) {};
	string getType() {
		return "Truck";
	}
	void getInfo() {
		cout << getType() << ":" << endl;
		cout << "Power of engine: " << engine.getPower() << "hp" << endl;
		cout << "Maximum speed: " << maxSpeed << "km/h" << endl;
		cout << "Maximum of cargo capacity: " << cargoCapacity << " tonn" << endl;
	}
};

int main() {
	Engine engine_car2 = 250;
	Car car1, car2(engine_car2, 170, 4);
	Engine engine_truck2 = 1000;
	Truck truck1, truck2(engine_truck2, 50, 100);

	Vehicle** arr_of_vehicles = new Vehicle* [4];
	arr_of_vehicles[0] = &car1;
	arr_of_vehicles[1] = &car2;
	arr_of_vehicles[2] = &truck1;
	arr_of_vehicles[3] = &truck2;

	for (int i = 0; i < 4; i++) {
		arr_of_vehicles[i]->getInfo();
		cout << endl;
	}

	return 0;
}