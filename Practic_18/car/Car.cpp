#include <iostream>
#include "Car.h"
#include "../validators/validators.h"

using namespace std;


// конструкторы

Car::Car() {
	this->_brend = "-";
	this->_color = "-";
	this->_bodyType = "-";
	this->_motorCapacity = 0;
	this->_mileage = 0;
}

// список инициализации

Car::Car(string brend, string color, string bodyType, double motorCapacity, int mileage) : _brend(validators::ValidateAlpha(brend)), 
_color(validators::ValidateAlpha(color)), _bodyType(validators::ValidateAlpha(bodyType)),
_motorCapacity(validators::ValidateNumber(motorCapacity)), _mileage(validators::ValidateNumber(mileage)) {}

// делегирование конструкторов

Car::Car(string brend, string color, string bodyType, double motorCapacity) : Car(brend, color, bodyType, motorCapacity, 0) {}
Car::Car(string brend, string color, string bodyType) : Car(brend, color, bodyType, 0, 0) {}
Car::Car(string brend, string color) : Car(brend, color, "-", 0, 0) {}
Car::Car(string brend) : Car(brend, "-", "-", 0, 0) {}

// деструкторы

Car::~Car() {}

// перегруз

Car Car::operator++() {
	this->_motorCapacity += 0.1;
	return *this;
}
Car Car::operator--() {
	if (this->_motorCapacity - 0.1 < 0) {
		cout << "Cannot decrement car motorCapacity on 0.1. MotorCapacity is less than 0.1 (" << this->_motorCapacity << ")" << endl;
	} else {
		this->_motorCapacity -= 0.1;
	}
	return *this;
}

bool Car::operator>(Car other) {
	return this->_motorCapacity > other._motorCapacity;
}
bool Car::operator<(Car other) {
	return this->_motorCapacity < other._motorCapacity;
}

ostream& operator<<(ostream& output, Car instance) {
	output << "Car: " << instance._brend
		<< " | Color: " << instance._color
		<< " | BodyType: " << instance._bodyType
		<< " | MotorCapacity: " << instance._motorCapacity
		<< " | Mileage: " << instance._mileage << endl;
	return output;
}

// сеттеры

void Car::setBrend(string brend) {
	this->_brend = brend;
}

void Car::setColor(string color) {
	this->_color = color;
}

void Car::setBodyType(string bodyType) {
	// если не входит в список допустимых значений
	if (bodyType == "sedan" || bodyType == "hatchback" || bodyType == "universal") {
		this->_bodyType = bodyType;
		return;
	}
	cout << "Error: Invalid bodyType was given! Available values: sedan || hatchback || universal" << endl;
}

void Car::setMotorCapacity(double motorCapacity) {
	// если меньше 0
	if (validators::ValidateNumber(motorCapacity) == 0) {
		return;
	}
	this->_motorCapacity = motorCapacity;
}

void Car::setMileage(int mileage) {
	// если меньше 0
	if (validators::ValidateNumber(mileage) == 0) {
		return;
	}
	this->_mileage = mileage;
}

// геттеры

string Car::getBrend() {
	return this->_brend;
}

string Car::getColor() {
	return this->_color;
}

string Car::getBodyType() {
	return this->_bodyType;
}

double Car::getMotorCapacity() {
	return this->_motorCapacity;
}

int Car::getMileage() {
	return this->_mileage;
}

// методы

double Car::averageFuelConsumption() {
	return this->_motorCapacity / this->_mileage * 100;
}

int Car::decreaseMileage(int amount) {
	this->_mileage -= amount;
	this->_mileage = validators::ValidateNumber(this->_mileage);
	return this->_mileage;
}
