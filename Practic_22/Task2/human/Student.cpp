#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;


Student::Student(string firstName, string lastName, int age, double weight, double height, string studyPlace, string workPlace, string livePlace) : 
	IHuman(firstName, lastName, age, weight, height), Child(studyPlace), Adult(workPlace), _livePlace(livePlace) {}
Student::Student() : Student("-", "-", 0, 0, 0, "-", "-", "-") {}

// деструктор
Student::~Student() {}

// перегруз

ostream& operator<<(ostream& output, Student instance) {
	output << "Student: " << instance.getFirstName() << " " << instance.getLastName()
		<< " | Age: " << instance.getAge()
		<< " | Weight: " << instance.getWeight()
		<< " | height: " << instance.getHeight()
		<< " | studyPlace: " << instance.getStudyPlace()
		<< " | workPlace: " << instance.getWorkPlace()
		<< " | livePlace: " << instance._livePlace << endl;
	return output;
}

// сеттеры

void Student::setLivePlace(string livePlace) {
	this->_livePlace = livePlace;
}

// геттеры

string Student::getLivePlace() {
	return this->_livePlace;
}

// методы

void Student::readFromConsole() {
	Child::readFromConsole();
	std::cout << "Enter work place: "; 

	string workPlace;
	cin >> workPlace;
	this->setWorkPlace(workPlace);

	std::cout << "Enter live place: "; 
	cin >> this->_livePlace;
}

void Student::writeToFile() {
	ofstream out;
	out.open("Peolpes.txt", ios::app);
	if (out.is_open()) {
		out << *this;
	}
	out.close();
}

void Student::print() {
	cout << "Student: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Weight: " << this->getWeight()
		<< " | height: " << this->getHeight()
		<< " | studyPlace: " << this->getStudyPlace()
		<< " | workPlace: " << this->getWorkPlace()
		<< " | livePlace: " << this->_livePlace << endl;
}
