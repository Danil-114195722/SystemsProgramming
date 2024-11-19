#include <iostream>
#include "Adult.h"

using namespace std;


// конструкторы

Adult::Adult() {
	this->setFirstName("-");
	this->setLastName("-");
	this->setAge(0);
	this->setWeight(0);
	this->setHeight(0);
	this->_workPlace = "-";
}

// список инициализации

Adult::Adult(string firstName, string lastName, int age, double weight, double height, string workPlace) : 
	Human(firstName, lastName, age, weight, height),
	_workPlace(workPlace) {}

// делегирование конструкторов

Adult::Adult(string firstName, string lastName, int age, double weight, double height) : Human(firstName, lastName, age, weight, height), _workPlace("-") {}
Adult::Adult(string firstName, string lastName, int age, double weight) : Human(firstName, lastName, age, weight, 0), _workPlace("-") {}
Adult::Adult(string firstName, string lastName, int age) : Human(firstName, lastName, age, 0, 0), _workPlace("-") {}
Adult::Adult(string firstName, string lastName) : Human(firstName, lastName, 0, 0, 0), _workPlace("-") {}
Adult::Adult(string firstName) : Human(firstName, "-", 0, 0, 0), _workPlace("-") {}

// деструкторы

Adult::~Adult() {
	cout << "~__Destr Adult " << this->getFirstName() << " " << this->getLastName() << "__" << endl;
}

// сеттеры

void Adult::setWorkPlace(string workPlace) {
	this->_workPlace = workPlace;
}

// геттеры

string Adult::getWorkPlace() {
	return this->_workPlace;
}

// методы

void Adult::print() {
	cout << "Adult: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Weight: " << this->getWeight()
		<< " | height: " << this->getHeight()
		<< " | workPlace: " << this->_workPlace << endl;
}
