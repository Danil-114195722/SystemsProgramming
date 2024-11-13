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
	Human(firstName, lastName, age, weight, height),
	_studyPlace(studyPlace) {}

// делегирование конструкторов

Child::Child(string firstName, string lastName, int age, double weight, double height) : Human(firstName, lastName, age, weight, height), _studyPlace("-") {}
Child::Child(string firstName, string lastName, int age, double weight) : Human(firstName, lastName, age, weight, 0), _studyPlace("-") {}
Child::Child(string firstName, string lastName, int age) : Human(firstName, lastName, age, 0, 0), _studyPlace("-") {}
Child::Child(string firstName, string lastName) : Human(firstName, lastName, 0, 0, 0), _studyPlace("-") {}
Child::Child(string firstName) : Human(firstName, "-", 0, 0, 0), _studyPlace("-") {}

// сеттеры

void Child::setStudyPlace(string studyPlace) {
	this->_studyPlace = studyPlace;
}

// геттеры

string Child::getStudyPlace() {
	return this->_studyPlace;
}

// методы

void Child::displayChild() {
	cout << "Child: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Weight: " << this->getWeight()
		<< " | height: " << this->getHeight()
		<< " | studyPlace: " << this->_studyPlace << endl;
}
