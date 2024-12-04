#include <iostream>
#include "./Actor.h"

using namespace std;


// конструкторы
Actor::Actor(string firstName, string lastName, int age, int experience, string gender, string education) :
	IPerson(firstName, lastName), IEmployee(firstName, lastName, age, experience), _gender(gender), _education(education) {}
Actor::Actor() : Actor("-", "-", 0, 0, "-", "-") {}

// деструктор
Actor::~Actor() {
	// cout << "___ ~Destr Actor " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// сеттеры

void Actor::setGender(string gender) {
	this->_gender = gender;
}

void Actor::setEducation(string education) {
	this->_education = education;
}

// геттеры

string Actor::getGender() {
	return this->_gender;
}

string Actor::getEducation() {
	return this->_education;
}

// методы

void Actor::print(string prefix) {
	cout << prefix << "Actor: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Experience: " << this->getExperience()
		<< " | Gender: " << this->_gender
		<< " | Education: " << this->_education << endl;
}
