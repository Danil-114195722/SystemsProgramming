#include <iostream>
#include "Employee.h"

using namespace std;


// конструкторы
Employee::Employee(string firstName, string lastName, int age, string post) : IPerson(firstName, lastName, age), _post(post) {}
Employee::Employee() : Employee("-", "-", 0, "-") {}

// деструктор
Employee::~Employee() {}

// сеттеры

void Employee::setPost(string post) {
	this->_post = post;
}

// геттеры

string Employee::getPost() {
	return this->_post;
}

// методы

void Employee::print(string prefixForSubarray) {
	cout << "Employee: " << this->getFirstName() << " " << this->getLastName()
		<< " | age: " << this->getAge()
		<< " | post: " << this->_post << endl;
}
