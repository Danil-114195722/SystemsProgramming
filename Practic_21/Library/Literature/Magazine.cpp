#include <iostream>
#include "Magazine.h"

using namespace std;


// конструкторы
Magazine::Magazine(int year, string publisher, string authorFullName, string title, string* themes, int themesSize) :
	ILiterature(year, publisher), Book(authorFullName, title), Newspaper(themes, themesSize) {}
Magazine::Magazine() : ILiterature(0, "-"), Book("-", "-") {
	string* temp = new string[0];
	this->setThemes(temp, 0);
	delete[] temp;
}

// деструктор
Magazine::~Magazine() {}

// методы

void Magazine::print(string prefixForSubarray) {
	cout << "Magazine: " << this->getTitle()
		<< " | Author: " << this->getAuthorFullName()
		<< " | Year: " << this->getYear()
		<< " | Publisher: " << this->getPublisher()
		<< " | Themes: ";
		
	int* themesSize = new int;
	*themesSize = this->getThemesSize();
	string* themes = this->getThemes();

	if (*themesSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < *themesSize; ++i) {
		cout << prefixForSubarray << "\t" << i << ". " << themes[i] << endl;
	}

	delete themesSize;
}
