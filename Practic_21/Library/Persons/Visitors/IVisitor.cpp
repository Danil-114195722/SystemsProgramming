#include <iostream>
#include "IVisitor.h"

using namespace std;


// конструкторы
IVisitor::IVisitor(string firstName, string lastName, int age, string phone, bool came) : IPerson(firstName, lastName, age),
	_phone(phone), _came(came) {}
IVisitor::IVisitor() : IVisitor("-", "-", 0, "-", false) {}

// деструктор
IVisitor::~IVisitor() {
	// cout << "___ ~Destr IVisitor " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// сеттеры

void IVisitor::setPhone(string phone) {
	this->_phone = phone;
}

void IVisitor::setCame(bool came) {
	this->_came = came;
}

// геттеры

string IVisitor::getPhone() {
	return this->_phone;
}

bool IVisitor::getCame() {
	return this->_came;
}
