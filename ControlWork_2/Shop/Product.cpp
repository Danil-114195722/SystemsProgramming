#include <iostream>
#include "./Product.h"

using namespace std;


// конструктор
Product::Product(string title, string manufacturer, string manufacturerCountry) :
	_title(title), _manufacturer(manufacturer), _manufacturerCountry(manufacturerCountry) {}

// деструктор
Product::~Product() {
	// cout << "___ ~Destr Product " << this->_title << " ___" << endl;
}

// геттеры

string Product::getTitle() {
	return this->_title;
}

string Product::getManufacturer() {
	return this->_manufacturer;
}

string Product::getManufacturerCountry() {
	return this->_manufacturerCountry;
}

// методы

void Product::print(string prefix) {
	cout << prefix << "Product: " << this->_title
		<< " | Manufacturer: " << this->_manufacturer
		<< " | Manufacturer country: " << this->_manufacturerCountry
		<< endl;
}
