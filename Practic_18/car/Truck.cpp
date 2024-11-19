#include <iostream>
#include "Truck.h"

using namespace std;


// конструкторы

Truck::Truck() {
	this->setBrend("-");
	this->setColor("-");
	this->setBodyType("-");
	this->setMotorCapacity(0);
	this->setMileage(0);
	this->_hasTrailer = false;
}

// список инициализации

Truck::Truck(string brend, string color, string bodyType, double motorCapacity, int mileage, bool hasTrailer) :
	Car(brend, color, bodyType, motorCapacity, mileage),
	_hasTrailer(hasTrailer) {}

// делегирование конструкторов

Truck::Truck(string brend, string color, string bodyType, double motorCapacity, int mileage) : Car(brend, color, bodyType, motorCapacity, mileage),
	_hasTrailer(false) {}
Truck::Truck(string brend, string color, string bodyType, double motorCapacity) : Car(brend, color, bodyType, motorCapacity, 0),
	_hasTrailer(false) {}
Truck::Truck(string brend, string color, string bodyType) : Car(brend, color, bodyType, 0, 0),
	_hasTrailer(false) {}
Truck::Truck(string brend, string color) : Car(brend, color, "-", 0, 0),
	_hasTrailer(false) {}
Truck::Truck(string brend) : Car(brend, "-", "-", 0, 0),
	_hasTrailer(false) {}

// сеттеры

void Truck::setHasTrailer(bool hasTrailer) {
	this->_hasTrailer = hasTrailer;
}

// геттеры

bool Truck::getHasTrailer() {
	return this->_hasTrailer;
}

// методы

void Truck::displayTruck() {
	cout << "Truck: " << this->getBrend()
		<< " | Color: " << this->getColor()
		<< " | BodyType: " << this->getBodyType()
		<< " | MotorCapacity: " << this->getMotorCapacity()
		<< " | Mileage: " << this->getMileage()
		<< " | HasTrailer: " << boolalpha << this->_hasTrailer << endl;
}
