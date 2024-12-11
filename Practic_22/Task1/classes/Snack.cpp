#include <iostream>
#include "Snack.h"

using namespace std;


Snack::Snack(string title, double calories, double price) : _title(title), _calories(calories), _price(price) {}

// деструктор
Snack::~Snack() {
	// cout << "__ ~Destr Snack __" << endl;
}

string Snack::getTitle() {
	return this->_title;
}
double Snack::getCalories() {
	return this->_calories;
}
double Snack::getPrice() {
	return this->_price;
}

void Snack::setNewPrice(double price) {
	this->_price = price;
}

void Snack::print() {
	cout << "Snack: " << this->_title
		<< " | Calories: " << this->_calories
		<< " | Price: " << this->_price << "$" << endl;
}
