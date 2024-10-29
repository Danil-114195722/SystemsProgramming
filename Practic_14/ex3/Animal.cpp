#include <iostream>
#include "Animal.h"

using namespace std;


// конструкторы

Animal::Animal() {
	cout << "___Constructor_" << name << "___" << endl;

	this->name = "-";
	this->species = "-";
	this->color = "-";
	this->age = 0;
	this->weight = 0;
}

Animal::Animal(string name) {
	cout << "___Constructor_" << name << "___" << endl;

	this->name = name;
	this->species = "-";
	this->color = "-";
	this->age = 0;
	this->weight = 0;
}

Animal::Animal(string name, string species) {
	cout << "___Constructor_" << name << "___" << endl;

	this->name = name;
	this->species = species;
	this->color = "-";
	this->age = 0;
	this->weight = 0;
}

Animal::Animal(string name, string species, string color) {
	cout << "___Constructor_" << name << "___" << endl;

	this->name = name;
	this->species = species;
	this->color = color;
	this->age = 0;
	this->weight = 0;
}

Animal::Animal(string name, string species, string color, int age) {
	cout << "___Constructor_" << name << "___" << endl;

	this->name = name;
	this->species = species;
	this->color = color;
	this->age = age;
	this->weight = 0;
}

Animal::Animal(string name, string species, string color, int age, double weight) {
	cout << "___Constructor_" << name << "___" << endl;

	this->name = name;
	this->species = species;
	this->color = color;
	this->age = age;
	this->weight = weight;
}

// деструкторы

Animal::~Animal() {
	cout << "___~Destructor_" << this->name << "___" << endl;
}

//сеттеры

void Animal::setName(string name) {
	this->name = name;
}

void Animal::setSpecies(string species) {
	this->species = species;
}

void Animal::setColor(string color) {
	this->color = color;
}

void Animal::setAge(int age) {
	// если меньше 0
	if (age < 0) {
		cout << "Error: Invalid age was given!" << endl;
		return;
	}
	this->age = age;
}

void Animal::setWeight(double weight) {
	// если меньше 0
	if (weight < 0) {
		cout << "Error: Invalid weight was given!" << endl;
		return;
	}
	this->weight = weight;
}

// геттеры

string Animal::getName() {
	return this->name;
}

string Animal::getSpecies() {
	return this->species;
}

string Animal::getColor() {
	return this->color;
}

int Animal::getAge() {
	return this->age;
}

double Animal::getWeight() {
	return this->weight;
}

// методы

void Animal::print() {
	cout << "Animal: " << this->name << " | Species: " << this->species;
	cout << " | Color: " << this->color << " | Age: " << this->age;
	cout << " | Weight: " << this->weight << endl;
}

double Animal::feed(int days) {
	this->weight += 0.01 * days;
	return this->weight;
}

string Animal::changeName(string newName) {
	this->name = newName;
	return newName;
}
