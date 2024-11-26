#define CURRENT_YEAR 2024
#include <iostream>
#include "Human.h"
#include "../validators/validators.h"

using namespace std;


// конструкторы

IHuman::IHuman(string firstName, string lastName, int age, double weight, double height) : _firstName(validators::ValidateAlpha(firstName)), 
_lastName(validators::ValidateAlpha(lastName)), _age(validators::ValidateNumber(age)),
_weight(validators::ValidateNumber(weight)), _height(validators::ValidateNumber(height)) {}
IHuman::IHuman() : IHuman("-", "-", 0, 0, 0) {}

// деструктор
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

void IHuman::readFromConsole() {
	std::cout << "Enter first name: "; 
	cin >> this->_firstName;

	std::cout << "Enter last name: "; 
	cin >> this->_lastName;
	
	std::cout << "Enter age: "; 
	cin >> this->_age;
	
	std::cout << "Enter weight: "; 
	cin >> this->_weight;
	
	std::cout << "Enter height: "; 
	cin >> this->_height;
}

void IHuman::writeToFile() {}

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
