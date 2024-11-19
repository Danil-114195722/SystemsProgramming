#include <iostream>
#include "Wild.h"

using namespace std;


// конструкторы

Wild::Wild() {
	this->setName("-");
	this->setSpecies("-");
	this->setColor("-");
	this->setAge(0);
	this->setWeight(0);
	this->_habitat = "-";
}

// список инициализации

Wild::Wild(string name, string species, string color, int age, double weight, string habitat) :
	Animal(name, species, color, age, weight),
	_habitat(habitat) {}

// делегирование конструкторов

Wild::Wild(string name, string species, string color, int age, double weight) : Animal(name, species, color, age, weight),
	_habitat("-") {}
Wild::Wild(string name, string species, string color, int age) : Animal(name, species, color, age, 0),
	_habitat("-") {}
Wild::Wild(string name, string species, string color) : Animal(name, species, color, 0, 0),
	_habitat("-") {}
Wild::Wild(string name, string species) : Animal(name, species, "-", 0, 0),
	_habitat("-") {}
Wild::Wild(string name) : Animal(name, "-", "-", 0, 0),
	_habitat("-") {}

// сеттеры

void Wild::setHabitat(string habitat) {
	this->_habitat = habitat;
}

// геттеры

string Wild::getHabitat() {
	return this->_habitat;
}

// методы

void Wild::displayWild() {
	cout << "Wild: " << this->getName()
		<< " | Species: " << this->getSpecies()
		<< " | Color: " << this->getColor()
		<< " | Age: " << this->getAge()
		<< " | Weight: " << this->getWeight()
		<< " | Habitat: " << this->_habitat << endl;
}
