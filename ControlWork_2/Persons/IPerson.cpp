#include <iostream>
#include "./IPerson.h"

using namespace std;


// конструкторы

IPerson::IPerson(string firstName, string lastName) : _firstName(firstName), _lastName(lastName) {}

// деструктор
IPerson::~IPerson() {
	// cout << "___ ~Destr IPerson " << this->_firstName << " " << this->_lastName << " ___" << endl;
}

// геттеры

string IPerson::getFirstName() {
	return this->_firstName;
}

string IPerson::getLastName() {
	return this->_lastName;
}
