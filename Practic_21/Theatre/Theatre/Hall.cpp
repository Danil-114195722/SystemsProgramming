#include <iostream>
#include "./Hall.h"

using namespace std;


// конструкторы
Hall::Hall(int number, int placeAmount) : _number(number), _placeAmount(placeAmount) {}
Hall::Hall() : Hall(0, 0) {}

// деструктор
Hall::~Hall() {
	// cout << "___ ~Destr Hall " << this->_number << " ___" << endl;
}

// геттеры

int Hall::getNumber() {
	return this->_number;
}
int Hall::getPlaceAmount() {
	return this->_placeAmount;
}

// сеттеры

void Hall::setNumber(int number) {
	this->_number = number;
}
void Hall::setPlaceAmount(int placeAmount) {
	this->_placeAmount = placeAmount;
}

// методы

void Hall::print(string prefix) {
	cout << prefix << "Hall: " << this->_number << " | Place amount: " << this->_placeAmount << endl;
}
