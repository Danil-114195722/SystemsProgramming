#include <iostream>
#include "Animal.h"
#include "../validators/validators.h"

using namespace std;


// конструкторы

Animal::Animal() {
	this->_name = "-";
	this->_species = "-";
	this->_color = "-";
	this->_age = 0;
	this->_weight = 0;
}

// список инициализации

Animal::Animal(string name, string species, string color, int age, double weight) : _name(validators::ValidateAlpha(name)), 
_species(validators::ValidateAlpha(species)), _color(validators::ValidateAlpha(color)),
_age(validators::ValidateNumber(age)), _weight(validators::ValidateNumber(weight)) {}

// делегирование конструкторов

Animal::Animal(string name, string species, string color, int age) : Animal(name, species, color, age, 0) {}
Animal::Animal(string name, string species, string color) : Animal(name, species, color, 0, 0) {}
Animal::Animal(string name, string species) : Animal(name, species, "-", 0, 0) {}
Animal::Animal(string name) : Animal(name, "-", "-", 0, 0) {}


// деструкторы

Animal::~Animal() {
}

// перегруз

Animal Animal::operator++() {
	++(this->_weight);
	return *this;
}
Animal Animal::operator--() {
	if (this->_weight - 1 < 0) {
		cout << "Cannot decrement animal weight. Weight is less than 1 (" << this->_weight << ")" << endl;
	} else {
		--(this->_weight);
		// return *this;
	}
	return *this;
}

bool Animal::operator>(Animal other) {
	return this->_weight > other._weight;
}
bool Animal::operator<(Animal other) {
	return this->_weight < other._weight;
}

ostream& operator<<(ostream& output, Animal instance) {
	output << "Animal: " << instance._name
		<< " | Species: " << instance._species
		<< " | Color: " << instance._color
		<< " | Age: " << instance._age
		<< " | Weight: " << instance._weight << endl;
	return output;
}

//сеттеры

void Animal::setName(string name) {
	this->_name = name;
}

void Animal::setSpecies(string species) {
	this->_species = species;
}

void Animal::setColor(string color) {
	this->_color = color;
}

void Animal::setAge(int age) {
	// если меньше 0
	if (validators::ValidateNumber(age) == 0) {
		return;
	}
	this->_age = age;
}

void Animal::setWeight(double weight) {
	// если меньше 0
	if (validators::ValidateNumber(weight) == 0) {
		return;
	}
	this->_weight = weight;
}

// геттеры

string Animal::getName() {
	return this->_name;
}

string Animal::getSpecies() {
	return this->_species;
}

string Animal::getColor() {
	return this->_color;
}

int Animal::getAge() {
	return this->_age;
}

double Animal::getWeight() {
	return this->_weight;
}

// методы

void Animal::print() {
	cout << "Animal: " << this->_name << " | Species: " << this->_species;
	cout << " | Color: " << this->_color << " | Age: " << this->_age;
	cout << " | Weight: " << this->_weight << endl;
}

double Animal::feed(int days) {
	this->_weight += 0.01 * days;
	return this->_weight;
}

string Animal::changeName(string newName) {
	this->_name = newName;
	return newName;
}
