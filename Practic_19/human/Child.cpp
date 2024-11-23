#include <iostream>
#include "Child.h"

using namespace std;


// конструкторы

Child::Child() {
	this->setFirstName("-");
	this->setLastName("-");
	this->setAge(0);
	this->setWeight(0);
	this->setHeight(0);
	this->_studyPlace = "-";
}

// список инициализации

Child::Child(string firstName, string lastName, int age, double weight, double height, string studyPlace) : 
	IHuman(firstName, lastName, age, weight, height),
	_studyPlace(studyPlace) {}

// делегирование конструкторов

Child::Child(string firstName, string lastName, int age, double weight, double height) : IHuman(firstName, lastName, age, weight, height), _studyPlace("-") {}
Child::Child(string firstName, string lastName, int age, double weight) : IHuman(firstName, lastName, age, weight, 0), _studyPlace("-") {}
Child::Child(string firstName, string lastName, int age) : IHuman(firstName, lastName, age, 0, 0), _studyPlace("-") {}
Child::Child(string firstName, string lastName) : IHuman(firstName, lastName, 0, 0, 0), _studyPlace("-") {}
Child::Child(string firstName) : IHuman(firstName, "-", 0, 0, 0), _studyPlace("-") {}

// деструкторы

Child::~Child() {}

// перегруз

Child Child::operator++() {
	this->setHeight(this->getHeight() + 0.1);
	return *this;
}
Child Child::operator--() {
	if (this->getHeight() - 0.1 < 0) {
		cout << "Cannot decrement child height on 0.1. Heigh is less than 0.1 (" << this->getHeight() << ")" << endl;
	} else {
		this->setHeight(this->getHeight() - 0.1);
	}
	return *this;
}

bool Child::operator>(Child other) {
	return this->getHeight() > other.getHeight();
}
bool Child::operator<(Child other) {
	return this->getHeight() < other.getHeight();
}

ostream& operator<<(ostream& output, Child instance) {
	output << "Child: " << instance.getFirstName() << " " << instance.getLastName()
		<< " | Age: " << instance.getAge()
		<< " | Weight: " << instance.getWeight()
		<< " | height: " << instance.getHeight()
		<< " | studyPlace: " << instance._studyPlace << endl;
	return output;
}

// сеттеры

void Child::setStudyPlace(string studyPlace) {
	this->_studyPlace = studyPlace;
}

// геттеры

string Child::getStudyPlace() {
	return this->_studyPlace;
}

// методы

void Child::print() {
	cout << "Child: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Weight: " << this->getWeight()
		<< " | height: " << this->getHeight()
		<< " | studyPlace: " << this->_studyPlace << endl;
}
