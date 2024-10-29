#define CURRENT_YEAR 2024
#include <iostream>
#include "Human.h"

using namespace std;


// конструкторы

Human::Human(string firstName) {
	cout << "___Constructor_" << firstName << "___" << endl;

	this->firstName = firstName;
	this->lastName = "";
	this->age = 0;
	this->weight = 0;
	this->height = 0;
}

Human::Human(string firstName, string lastName) {
	cout << "___Constructor_" << firstName << "___" << endl;

	this->firstName = firstName;
	this->lastName = lastName;
	this->age = 0;
	this->weight = 0;
	this->height = 0;
}

Human::Human(string firstName, string lastName, int age) {
	cout << "___Constructor_" << firstName << "___" << endl;

	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->weight = 0;
	this->height = 0;
}

Human::Human(string firstName, string lastName, int age, double weight) {
	cout << "___Constructor_" << firstName << "___" << endl;

	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->weight = weight;
	this->height = 0;
}

Human::Human(string firstName, string lastName, int age, double weight, double height) {
	cout << "___Constructor_" << firstName << "___" << endl;

	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
	this->weight = weight;
	this->height = height;
}

// деструкторы

Human::~Human() {
	cout << "___~Destructor_" << this->firstName << "___" << endl;
}

//сеттеры

void Human::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Human::setLastName(string lastName) {
	this->lastName = lastName;
}

void Human::setAge(int age) {
	// если переданный возраст меньше нуля
	if (age < 0) {
		cout << "Error: Invalid age was given!" << endl;
		return;
	}

	this->age = age;
}

void Human::setWeight(double weight) {
	// если переданная масса меньше минимальной
	if (weight < 1) {
		cout << "Error: Invalid weight was given!" << endl;
		return;
	}

	this->weight = weight;
}

void Human::setHeight(double height) {
	// если переданный рост меньше минимального
	if (height < 0.35) {
		cout << "Error: Invalid height was given!" << endl;
		return;
	}

	this->height = height;
}

// геттеры

string Human::getFirstName() {
	return this->firstName;
}

string Human::getLastName() {
	return this->lastName;
}

int Human::getAge() {
	return this->age;
}

double Human::getWeight() {
	return this->weight;
}

double Human::getHeight() {
	return this->height;
}

// методы

void Human::print() {
	cout << "Human: ";

	if (firstName == "") {
		cout << "- ";
	} else {
		cout << firstName << " ";
	}

	if (lastName == "") {
		cout << "-";
	} else {
		cout << lastName;
	}

	cout << " | Age: " << age << " | Weight: " << weight << " | height: " << height << endl;
}

double Human::bodyWeightIndex() {
	return weight / (height * height);
}

int Human::bornYear() {
	return CURRENT_YEAR - age;
}
