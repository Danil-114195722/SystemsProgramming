#include <iostream>
#include "./IPerson.h"

using namespace std;


// конструкторы

IPerson::IPerson(string firstName, string lastName) : _firstName(firstName), _lastName(lastName) {}
IPerson::IPerson() : IPerson("-", "-") {}

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

// геттеры

string IPerson::getFirstName() {
	return this->_firstName;
}

string IPerson::getLastName() {
	return this->_lastName;
}
