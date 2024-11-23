#define CURRENT_YEAR 2024
#include <iostream>
#include "Human.h"
#include "../validators/validators.h"

using namespace std;


// конструкторы

IHuman::IHuman() {
	this->_firstName = "-";
	this->_lastName = "-";
	this->_age = 0;
	this->_weight = 0;
	this->_height = 0;
}

// список инициализации

IHuman::IHuman(string firstName, string lastName, int age, double weight, double height) : _firstName(validators::ValidateAlpha(firstName)), 
_lastName(validators::ValidateAlpha(lastName)), _age(validators::ValidateNumber(age)),
_weight(validators::ValidateNumber(weight)), _height(validators::ValidateNumber(height)) {}

// делегирование конструкторов

// IHuman::IHuman(string firstName, string lastName, int age, double weight) : IHuman(firstName, lastName, age, weight, 0) {}
// IHuman::IHuman(string firstName, string lastName, int age) : IHuman(firstName, lastName, age, 0, 0) {}
// IHuman::IHuman(string firstName, string lastName) : IHuman(firstName, lastName, 0, 0, 0) {}
// IHuman::IHuman(string firstName) : IHuman(firstName, "-", 0, 0, 0) {}

// деструкторы

IHuman::~IHuman() {}

// сеттеры

void IHuman::setFirstName(string firstName) {
	this->_firstName = firstName;
}

void IHuman::setLastName(string lastName) {
	this->_lastName = lastName;
}

void IHuman::setAge(int age) {
	// если переданный возраст меньше нуля
	if (validators::ValidateNumber(age) == 0) {
		return;
	}
	this->_age = age;
}

void IHuman::setWeight(double weight) {
	// если переданная масса меньше минимальной
	if (validators::ValidateNumber(weight) == 0) {
		return;
	}
	this->_weight = weight;
}

void IHuman::setHeight(double height) {
	// если переданный рост меньше минимального
	if (validators::ValidateNumber(height) == 0) {
		return;
	}
	this->_height = height;
}

// геттеры

string IHuman::getFirstName() {
	return this->_firstName;
}

string IHuman::getLastName() {
	return this->_lastName;
}

int IHuman::getAge() {
	return this->_age;
}

double IHuman::getWeight() {
	return this->_weight;
}

double IHuman::getHeight() {
	return this->_height;
}

// методы

void IHuman::print() {
	cout << "IHuman: " << this->_firstName << " " << this->_lastName
		<< " | Age: " << this->_age
		<< " | Weight: " << this->_weight
		<< " | height: " << this->_height << endl;
}

double IHuman::bodyWeightIndex() {
	return _weight / (_height * _height);
}

int IHuman::bornYear() {
	return CURRENT_YEAR - _age;
}
