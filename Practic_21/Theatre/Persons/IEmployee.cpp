#include <iostream>
#include "./IEmployee.h"

using namespace std;


// конструкторы
IEmployee::IEmployee(string firstName, string lastName, int age, int experience) :
	IPerson(firstName, lastName), _age(age), _experience(experience) {}
IEmployee::IEmployee() : IEmployee("-", "-", 0, 0) {}

// деструктор
IEmployee::~IEmployee() {
	// cout << "___ ~Destr IEmployee " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// сеттеры

void IEmployee::setAge(int age) {
	this->_age = age;
}

void IEmployee::setExperience(int experience) {
	this->_experience = experience;
}

// геттеры

int IEmployee::getAge() {
	return this->_age;
}

int IEmployee::getExperience() {
	return this->_experience;
}
