#include <iostream>
#include "./Client.h"

using namespace std;


// конструкторы
Client::Client(string firstName, string lastName, string phone) : IPerson(firstName, lastName), _phone(phone) {}

// деструктор
Client::~Client() {
	// cout << "___ ~Destr Client " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// геттеры

string Client::getPhone() {
	return this->_phone;
}

// методы

void Client::print(string prefix) {
	cout << prefix << "Client: " << this->getFirstName() << " " << this->getLastName()
		<< " | Phone: " << this->_phone << endl;
}
