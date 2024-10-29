#include <iostream>
#include "Car.h"

using namespace std;


// конструкторы

Car::Car() {
	cout << "___Constructor_" << brend << "___" << endl;

	this->brend = "-";
	this->color = "-";
	this->bodyType = "-";
	this->motorCapacity = 0;
	this->mileage = 0;
}

Car::Car(string brend) {
	cout << "___Constructor_" << brend << "___" << endl;

	this->brend = brend;
	this->color = "-";
	this->bodyType = "-";
	this->motorCapacity = 0;
	this->mileage = 0;
}

Car::Car(string brend, string color) {
	cout << "___Constructor_" << brend << "___" << endl;

	this->brend = brend;
	this->color = color;
	this->bodyType = "-";
	this->motorCapacity = 0;
	this->mileage = 0;
}

Car::Car(string brend, string color, string bodyType) {
	cout << "___Constructor_" << brend << "___" << endl;

	this->brend = brend;
	this->color = color;
	this->bodyType = bodyType;
	this->motorCapacity = 0;
	this->mileage = 0;
}

Car::Car(string brend, string color, string bodyType, double motorCapacity) {
	cout << "___Constructor_" << brend << "___" << endl;

	this->brend = brend;
	this->color = color;
	this->bodyType = bodyType;
	this->motorCapacity = motorCapacity;
	this->mileage = 0;
}

Car::Car(string brend, string color, string bodyType, double motorCapacity, int mileage) {
	cout << "___Constructor_" << brend << "___" << endl;

	this->brend = brend;
	this->color = color;
	this->bodyType = bodyType;
	this->motorCapacity = motorCapacity;
	this->mileage = mileage;
}

// деструкторы

Car::~Car() {
	cout << "___~Destructor_" << this->brend << "___" << endl;
}

//сеттеры

void Car::setBrend(string brend) {
	this->brend = brend;
}

void Car::setColor(string color) {
	this->color = color;
}

void Car::setBodyType(string bodyType) {
	// если не входит в список допустимых значений
	if (bodyType == "sedan" || bodyType == "hatchback" || bodyType == "universal") {
		this->bodyType = bodyType;
		return;
	}
	cout << "Error: Invalid bodyType was given! Available values: sedan || hatchback || universal" << endl;
}

void Car::setMotorCapacity(double motorCapacity) {
	// если меньше 0
	if (motorCapacity < 0) {
		cout << "Error: Invalid motorCapacity was given!" << endl;
		return;
	}
	this->motorCapacity = motorCapacity;
}

void Car::setMileage(int mileage) {
	// если меньше 0
	if (mileage < 0) {
		cout << "Error: Invalid mileage was given!" << endl;
		return;
	}
	this->mileage = mileage;
}

// геттеры

string Car::getBrend() {
	return this->brend;
}

string Car::getColor() {
	return this->color;
}

string Car::getBodyType() {
	return this->bodyType;
}

double Car::getMotorCapacity() {
	return this->motorCapacity;
}

int Car::getMileage() {
	return this->mileage;
}

// методы

void Car::print() {
	cout << "Car: " << this->brend << " | Color: " << this->color;
	cout << " | BodyType: " << this->bodyType << " | MotorCapacity: " << this->motorCapacity;
	cout << " | Mileage: " << this->mileage << endl;
}

double Car::averageFuelConsumption() {
	return this->motorCapacity / this->mileage * 100;
}

int Car::decreaseMileage(int amount) {
	this->mileage -= amount;
	if (this->mileage < 0) {
		this->mileage = 0;
	}
	return this->mileage;
}
