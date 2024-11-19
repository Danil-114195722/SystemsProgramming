#include <iostream>
#include "Pet.h"

using namespace std;


// конструкторы

Pet::Pet() {
	this->setName("-");
	this->setSpecies("-");
	this->setColor("-");
	this->setAge(0);
	this->setWeight(0);
	this->_owner = "-";
}

// список инициализации

Pet::Pet(string name, string species, string color, int age, double weight, string owner) :
	Animal(name, species, color, age, weight),
	_owner(owner) {}

// делегирование конструкторов

Pet::Pet(string name, string species, string color, int age, double weight) : Animal(name, species, color, age, weight),
	_owner("-") {}
Pet::Pet(string name, string species, string color, int age) : Animal(name, species, color, age, 0),
	_owner("-") {}
Pet::Pet(string name, string species, string color) : Animal(name, species, color, 0, 0),
	_owner("-") {}
Pet::Pet(string name, string species) : Animal(name, species, "-", 0, 0),
	_owner("-") {}
Pet::Pet(string name) : Animal(name, "-", "-", 0, 0),
	_owner("-") {}

// сеттеры

void Pet::setOwner(string owner) {
	this->_owner = owner;
}

// геттеры

string Pet::getOwner() {
	return this->_owner;
}

// методы

void Pet::displayPet() {
	cout << "Pet: " << this->getName()
		<< " | Species: " << this->getSpecies()
		<< " | Color: " << this->getColor()
		<< " | Age: " << this->getAge()
		<< " | Weight: " << this->getWeight()
		<< " | Owner: " << this->_owner << endl;
}
