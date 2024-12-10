#define CURRENT_YEAR 2024
#include <iostream>
#include "Human.h"
#include "../validators/validators.h"

using namespace std;
using namespace human;


// конструкторы

IHuman::IHuman(string firstName, string lastName, int age, double weight, double height) : _firstName(validators::ValidateAlpha(firstName)), 
	_lastName(validators::ValidateAlpha(lastName)), _age(validators::ValidateNumber(age)),
	_weight(validators::ValidateNumber(weight)), _height(validators::ValidateNumber(height)) {}
IHuman::IHuman() : IHuman("-", "-", 0, 0, 0) {}

// деструктор
IHuman::~IHuman() {}

// сеттеры

void IHuman::setFirstName(string firstName) {
	if (validators::ValidateAlpha(firstName) == "-") {
		return;
	}
	this->_firstName = firstName;
}

void IHuman::setLastName(string lastName) {
	if (validators::ValidateAlpha(lastName) == "-") {
		return;
	}
	this->_lastName = lastName;
}

void IHuman::setAge(int age) {
	// если переданный возраст меньше нуля
	if (validators::ValidateNumber(age) == 0) {
		return;
	}
	this->_age = age;
}

void IHuman::setWeight(double weight) {
	// если переданная масса меньше минимальной
	if (validators::ValidateNumber(weight) == 0) {
		return;
	}
	this->_weight = weight;
}

void IHuman::setHeight(double height) {
	// если переданный рост меньше минимального
	if (validators::ValidateNumber(height) == 0) {
		return;
	}
	this->_height = height;
}

// геттеры

string IHuman::getFirstName() {
	return this->_firstName;
}

string IHuman::getLastName() {
	return this->_lastName;
}

int IHuman::getAge() {
	return this->_age;
}

double IHuman::getWeight() {
	return this->_weight;
}

double IHuman::getHeight() {
	return this->_height;
}

// методы

void IHuman::readFromConsole() {
	string* tempFirstName = new string;
	string* tempLastName = new string;
	string* tempAge = new string;
	double* tempWeight = new double;
	double* tempHeight = new double;

	std::cout << "Enter first name: "; 
	cin >> *tempFirstName;
	this->setFirstName(*tempFirstName);

	std::cout << "Enter last name: "; 
	cin >> *tempLastName;
	this->setLastName(*tempLastName);
	
	std::cout << "Choose the one of age samples or enter your own value of age:" << endl; 
	std::cout << "\ta (sampleBaby)" << endl;
	std::cout << "\tb (sampleYoung)" << endl;
	std::cout << "\tc (sampleMiddle)" << endl;
	std::cout << "\td (sampleOld)" << endl;
	std::cout << "\t[or enter your own value]" << endl;
	std::cout << "Age: ";
	cin >> *tempAge;

	if (*tempAge == "a") {
		this->setAge(age::sampleBaby);
		std::cout << "Used sampleBaby value: " << age::sampleBaby << endl;
	} else if (*tempAge == "b") {
		this->setAge(age::sampleYoung);
		std::cout << "Used sampleYoung value: " << age::sampleYoung << endl;
	} else if (*tempAge == "c") {
		this->setAge(age::sampleMiddle);
		std::cout << "Used sampleMiddle value: " << age::sampleMiddle << endl;
	} else if (*tempAge == "d") {
		this->setAge(age::sampleOld);
		std::cout << "Used sampleOld value: " << age::sampleOld << endl;
	} else {
		this->setAge(stoi(*tempAge));
	}
	
	std::cout << "Enter weight: "; 
	cin >> *tempWeight;
	this->setWeight(*tempWeight);
	
	std::cout << "Enter height: "; 
	cin >> *tempHeight;
	this->setHeight(*tempHeight);

	delete tempFirstName;
	delete tempLastName;
	delete tempAge;
	delete tempWeight;
	delete tempHeight;
}

double IHuman::bodyWeightIndex() {
	return _weight / (_height * _height);
}

int IHuman::bornYear() {
	return CURRENT_YEAR - _age;
}
