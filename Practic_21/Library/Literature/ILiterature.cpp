#include <iostream>
#include "ILiterature.h"

using namespace std;


// конструкторы

ILiterature::ILiterature(int year, string publisher) : _year(year), _publisher(publisher) {}
ILiterature::ILiterature() : ILiterature(0, "-") {}

// деструктор
ILiterature::~ILiterature() {}

// сеттеры

void ILiterature::setPublisher(string publisher) {
	this->_publisher = publisher;
}

void ILiterature::setYear(int year) {
	this->_year = year;
}

// геттеры

string ILiterature::getPublisher() {
	return this->_publisher;
}

int ILiterature::getYear() {
	return this->_year;
}
