#include <iostream>
#include <fstream>
#include "Adult.h"

using namespace std;


// конструкторы

Adult::Adult(string firstName, string lastName, int age, double weight, double height, string workPlace) : 
	IHuman(firstName, lastName, age, weight, height), _workPlace(workPlace) {}
Adult::Adult(string workPlace) : Adult("-", "-", 0, 0, 0, workPlace) {}
Adult::Adult() : Adult("-", "-", 0, 0, 0, "-") {}

// деструктор
Adult::~Adult() {}

// перегруз

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

void Adult::readFromConsole() {
	IHuman::readFromConsole();
	std::cout << "Enter work place: "; 
	cin >> this->_workPlace;
}

void Adult::writeToFile() {
	ofstream out;
	out.open("Peolpes.txt", ios::app);
	if (out.is_open()) {
		out << *this;
	}
	out.close();
}

void Adult::print() {
	cout << "Adult: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Weight: " << this->getWeight()
		<< " | height: " << this->getHeight()
		<< " | workPlace: " << this->_workPlace << endl;
}
