#include <iostream>
#include "PassangerCar.h"

using namespace std;


// конструкторы

PassangerCar::PassangerCar() {
	this->setBrend("-");
	this->setColor("-");
	this->setBodyType("-");
	this->setMotorCapacity(0);
	this->setMileage(0);
	this->_hasArmrest = false;
}

// список инициализации

PassangerCar::PassangerCar(string brend, string color, string bodyType, double motorCapacity, int mileage, bool hasArmrest) :
	Car(brend, color, bodyType, motorCapacity, mileage),
	_hasArmrest(hasArmrest) {}

// делегирование конструкторов

PassangerCar::PassangerCar(string brend, string color, string bodyType, double motorCapacity, int mileage) : Car(brend, color, bodyType, motorCapacity, mileage),
	_hasArmrest(false) {}
PassangerCar::PassangerCar(string brend, string color, string bodyType, double motorCapacity) : Car(brend, color, bodyType, motorCapacity, 0),
	_hasArmrest(false) {}
PassangerCar::PassangerCar(string brend, string color, string bodyType) : Car(brend, color, bodyType, 0, 0),
	_hasArmrest(false) {}
PassangerCar::PassangerCar(string brend, string color) : Car(brend, color, "-", 0, 0),
	_hasArmrest(false) {}
PassangerCar::PassangerCar(string brend) : Car(brend, "-", "-", 0, 0),
	_hasArmrest(false) {}

// сеттеры

void PassangerCar::setHasArmrest(bool hasArmrest) {
	this->_hasArmrest = hasArmrest;
}

// геттеры

bool PassangerCar::getHasArmrest() {
	return this->_hasArmrest;
}

// методы

void PassangerCar::displayPassangerCar() {
	cout << "PassangerCar: " << this->getBrend()
		<< " | Color: " << this->getColor()
		<< " | BodyType: " << this->getBodyType()
		<< " | MotorCapacity: " << this->getMotorCapacity()
		<< " | Mileage: " << this->getMileage()
		<< " | HasArmrest: " << boolalpha << this->_hasArmrest << endl;
}
