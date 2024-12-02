#include <iostream>
#include "Book.h"

using namespace std;


// конструкторы
Book::Book(string authorFullName, string title) : _authorFullName(authorFullName), _title(title) {}
Book::Book(int year, string publisher, string authorFullName, string title, string genre) :
	ILiterature(year, publisher), _authorFullName(authorFullName), _title(title), _genre(genre) {}
Book::Book() : Book(0, "-", "-", "-", "-") {}

// деструктор
Book::~Book() {}

// сеттеры

void Book::setAuthorFullName(string authorFullName) {
	this->_authorFullName = authorFullName;
}

void Book::setTitle(string title) {
	this->_title = title;
}

void Book::setGenre(string genre) {
	this->_genre = genre;
}

// геттеры

string Book::getAuthorFullName() {
	return this->_authorFullName;
}

string Book::getTitle() {
	return this->_title;
}

string Book::getGenre() {
	return this->_genre;
}

// методы

void Book::print(string prefixForSubarray) {
	cout << "Book: " << this->_title
		<< " | Author: " << this->_authorFullName
		<< " | Genre: " << this->_genre
		<< " | Year: " << this->getYear()
		<< " | Publisher: " << this->getPublisher() << endl;
}
