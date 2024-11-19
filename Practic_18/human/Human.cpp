#define CURRENT_YEAR 2024
#include <iostream>
#include "Human.h"
#include "../validators/validators.h"

using namespace std;


// конструкторы

Human::Human() {
	this->_firstName = "-";
	this->_lastName = "-";
	this->_age = 0;
	this->_weight = 0;
	this->_height = 0;
}

// список инициализации

Human::Human(string firstName, string lastName, int age, double weight, double height) : _firstName(validators::ValidateAlpha(firstName)), 
_lastName(validators::ValidateAlpha(lastName)), _age(validators::ValidateNumber(age)),
_weight(validators::ValidateNumber(weight)), _height(validators::ValidateNumber(height)) {}

// делегирование конструкторов

Human::Human(string firstName, string lastName, int age, double weight) : Human(firstName, lastName, age, weight, 0) {}
Human::Human(string firstName, string lastName, int age) : Human(firstName, lastName, age, 0, 0) {}
Human::Human(string firstName, string lastName) : Human(firstName, lastName, 0, 0, 0) {}
Human::Human(string firstName) : Human(firstName, "-", 0, 0, 0) {}

// деструкторы

Human::~Human() {
	cout << "~__Destr Human " << this->_firstName << " " << this->_lastName << "__" << endl;
}

// перегруз

Human Human::operator++() {
	this->_height += 0.1;
	return *this;
}
Human Human::operator--() {
	if (this->_height - 0.1 < 0) {
		cout << "Cannot decrement human height on 0.1. Heigh is less than 0.1 (" << this->_height << ")" << endl;
	} else {
		this->_height -= 0.1;
	}
	return *this;
}

bool Human::operator>(Human other) {
	return this->_height > other._height;
}
bool Human::operator<(Human other) {
	return this->_height < other._height;
}

ostream& operator<<(ostream& output, Human instance) {
	output << "Human: " << instance._firstName << " " << instance._lastName
		<< " | Age: " << instance._age
		<< " | Weight: " << instance._weight
		<< " | height: " << instance._height << endl;
	return output;
}

// сеттеры

void Human::setFirstName(string firstName) {
	this->_firstName = firstName;
}

void Human::setLastName(string lastName) {
	this->_lastName = lastName;
}

void Human::setAge(int age) {
	// если переданный возраст меньше нуля
	if (validators::ValidateNumber(age) == 0) {
		return;
	}
	this->_age = age;
}

void Human::setWeight(double weight) {
	// если переданная масса меньше минимальной
	if (validators::ValidateNumber(weight) == 0) {
		return;
	}
	this->_weight = weight;
}

void Human::setHeight(double height) {
	// если переданный рост меньше минимального
	if (validators::ValidateNumber(height) == 0) {
		return;
	}
	this->_height = height;
}

// геттеры

string Human::getFirstName() {
	return this->_firstName;
}

string Human::getLastName() {
	return this->_lastName;
}

int Human::getAge() {
	return this->_age;
}

double Human::getWeight() {
	return this->_weight;
}

double Human::getHeight() {
	return this->_height;
}

// методы

void Human::print() {
	cout << "Human: " << this->_firstName << " " << this->_lastName
		<< " | Age: " << this->_age
		<< " | Weight: " << this->_weight
		<< " | height: " << this->_height << endl;
}

double Human::bodyWeightIndex() {
	return _weight / (_height * _height);
}

int Human::bornYear() {
	return CURRENT_YEAR - _age;
}
