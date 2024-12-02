#include <iostream>
#include "IPerson.h"

using namespace std;


// конструкторы

IPerson::IPerson(string firstName, string lastName, int age) : _firstName(firstName), _lastName(lastName), _age(age) {}
IPerson::IPerson() : IPerson("-", "-", 0) {}

// деструктор
IPerson::~IPerson() {
	// cout << "___ ~Destr IPerson " << this->_firstName << " " << this->_lastName << " ___" << endl;
}

// сеттеры

void IPerson::setFirstName(string firstName) {
	this->_firstName = firstName;
}

void IPerson::setLastName(string lastName) {
	this->_lastName = lastName;
}

void IPerson::setAge(int age) {
	this->_age = age;
}

// геттеры

string IPerson::getFirstName() {
	return this->_firstName;
}

string IPerson::getLastName() {
	return this->_lastName;
}

int IPerson::getAge() {
	return this->_age;
}
