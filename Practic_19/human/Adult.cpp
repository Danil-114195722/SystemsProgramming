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
	IHuman(firstName, lastName, age, weight, height),
	_workPlace(workPlace) {}

// делегирование конструкторов

Adult::Adult(string firstName, string lastName, int age, double weight, double height) : IHuman(firstName, lastName, age, weight, height), _workPlace("-") {}
Adult::Adult(string firstName, string lastName, int age, double weight) : IHuman(firstName, lastName, age, weight, 0), _workPlace("-") {}
Adult::Adult(string firstName, string lastName, int age) : IHuman(firstName, lastName, age, 0, 0), _workPlace("-") {}
Adult::Adult(string firstName, string lastName) : IHuman(firstName, lastName, 0, 0, 0), _workPlace("-") {}
Adult::Adult(string firstName) : IHuman(firstName, "-", 0, 0, 0), _workPlace("-") {}

// деструкторы

Adult::~Adult() {}

// перегруз

Adult Adult::operator++() {
	this->setHeight(this->getHeight() + 0.1);
	return *this;
}
Adult Adult::operator--() {
	if (this->getHeight() - 0.1 < 0) {
		cout << "Cannot decrement adult height on 0.1. Heigh is less than 0.1 (" << this->getHeight() << ")" << endl;
	} else {
		this->setHeight(this->getHeight() - 0.1);
	}
	return *this;
}

bool Adult::operator>(Adult other) {
	return this->getHeight() > other.getHeight();
}
bool Adult::operator<(Adult other) {
	return this->getHeight() < other.getHeight();
}

ostream& operator<<(ostream& output, Adult instance) {
	output << "Adult: " << instance.getFirstName() << " " << instance.getLastName()
		<< " | Age: " << instance.getAge()
		<< " | Weight: " << instance.getWeight()
		<< " | height: " << instance.getHeight()
		<< " | workPlace: " << instance._workPlace << endl;
	return output;
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
