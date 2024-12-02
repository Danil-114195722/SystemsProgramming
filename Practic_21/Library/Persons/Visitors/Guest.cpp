#include <iostream>
#include "Guest.h"

using namespace std;


// конструкторы
Guest::Guest(string firstName, string lastName, int age, string phone, bool came) : IVisitor(firstName, lastName, age, phone, came) {
	this->_literatureToRead = new ILiterature*[0];
	this->_literatureToReadSize = 0;
}
Guest::Guest() : Guest("-", "-", 0, "-", false) {}

// деструктор
Guest::~Guest() {
	delete[] this->_literatureToRead;
	// cout << "___ ~Destr Guest " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// геттеры

ILiterature** Guest::getLiteratureToRead() {
	return this->_literatureToRead;
}

int Guest::getLiteratureToReadSize() {
	return this->_literatureToReadSize;
}

// методы

void Guest::addLiteratureToRead(ILiterature* literatureToRead) {
	// копируем всю литературу объекта во временный массив temp
	ILiterature** temp = new ILiterature*[this->_literatureToReadSize];
	for(int i = 0; i < this->_literatureToReadSize; ++i) {
		temp[i] = this->_literatureToRead[i];
	}
	delete[] this->_literatureToRead;

	// копируем всю литературу из временного массива temp обратно в массив объекта
	this->_literatureToRead = new ILiterature*[this->_literatureToReadSize+1];
	for(int i = 0; i < this->_literatureToReadSize; ++i) {
		this->_literatureToRead[i] = temp[i];
	}
	// добавляем новую литературу в конец массива объекта
	this->_literatureToRead[this->_literatureToReadSize] = literatureToRead;

	this->_literatureToReadSize++;
	delete[] temp;
}

void Guest::deleteLiteratureToRead(int literatureToReadIdx) {
	if (literatureToReadIdx >= this->_literatureToReadSize || literatureToReadIdx < 0) {
		cout << "Error: invalid literatureToReadIdx was given!" << endl;
		return;
	}
	// копируем всю литературу объекта во временный массив temp
	ILiterature** temp = new ILiterature*[this->_literatureToReadSize];
	for(int i = 0; i < this->_literatureToReadSize; ++i) {
		temp[i] = this->_literatureToRead[i];
	}
	delete[] this->_literatureToRead;

	// копируем всю литературу из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_literatureToRead = new ILiterature*[this->_literatureToReadSize-1];
	for(int i = 0; i < literatureToReadIdx; ++i) {
		this->_literatureToRead[i] = temp[i];
	}
	for(int i = literatureToReadIdx+1; i < this->_literatureToReadSize; ++i) {
		this->_literatureToRead[i-1] = temp[i];
	}

	this->_literatureToReadSize--;
	delete[] temp;
}

void Guest::print(string prefixForSubarray) {
	cout << "Guest: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Phone: " << this->getPhone()
		<< " | Came: " << boolalpha << this->getCame()
		<< " | LiteratureToRead: ";

	if (this->_literatureToReadSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_literatureToReadSize; ++i) {
		cout << prefixForSubarray << "\t" << i << ". ";
		this->_literatureToRead[i]->print(prefixForSubarray + "\t");
	}
}
