#include <iostream>
#include "Newspaper.h"

using namespace std;


// конструкторы
Newspaper::Newspaper(string* themes, int themesSize) {
	this->_themes = new string[themesSize];
	this->_themesSize = themesSize;

	for(int i = 0; i < themesSize; ++i) {
		this->_themes[i] = themes[i];
	}
}
Newspaper::Newspaper(int year, string publisher, string* themes, int themesSize) : ILiterature(year, publisher) {
	this->_themes = new string[themesSize];
	this->_themesSize = themesSize;

	for(int i = 0; i < themesSize; ++i) {
		this->_themes[i] = themes[i];
	}
}
Newspaper::Newspaper() : ILiterature(0, "-") {
	this->_themes = new string[0];
	this->_themesSize = 0;
}

// деструктор
Newspaper::~Newspaper() {}

// сеттеры

void Newspaper::setThemes(string* themes, int themesSize) {
	delete[] this->_themes;
	
	this->_themes = new string[themesSize];
	this->_themesSize = themesSize;

	for(int i = 0; i < themesSize; ++i) {
		this->_themes[i] = themes[i];
	}
}

// геттеры

string* Newspaper::getThemes() {
	return this->_themes;
}

int Newspaper::getThemesSize() {
	return this->_themesSize;
}

// методы

void Newspaper::print(string prefixForSubarray) {
	cout << "Newspaper"
		<< " | Year: " << this->getYear()
		<< " | Publisher: " << this->getPublisher()
		<< " | Themes: ";
		
	if (this->_themesSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_themesSize; ++i) {
		cout << prefixForSubarray << "\t" << i << ". " << this->_themes[i] << endl;
	}
}
