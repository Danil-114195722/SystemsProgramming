#include <iostream>
#include "Client.h"

using namespace std;


// конструкторы
Client::Client(string firstName, string lastName, int age, string phone, bool came, string cardId, ILiterature** takenLiterature, int takenLiteratureSize) : 
	IVisitor(firstName, lastName, age, phone, came), _cardId(cardId) {
		this->_takenLiterature = new ILiterature*[takenLiteratureSize];
		this->_takenLiteratureSize = takenLiteratureSize;

		for(int i = 0; i < takenLiteratureSize; ++i) {
			this->_takenLiterature[i] = takenLiterature[i];
		}
}

Client::Client(string firstName, string lastName, int age, string phone, bool came, string cardId) : 
	IVisitor(firstName, lastName, age, phone, came), _cardId(cardId) {
		this->_takenLiterature = new ILiterature*[0];
		this->_takenLiteratureSize = 0;
}
Client::Client() : Client("-", "-", 0, "-", false, "00000") {}

// деструктор
Client::~Client() {
	delete[] this->_takenLiterature;
	// cout << "___ ~Destr Client " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// сеттеры

void Client::setCardId(string cardId) {
	this->_cardId = cardId;
}

// геттеры

string Client::getCardId() {
	return this->_cardId;
}

ILiterature** Client::getTakenLiterature() {
	return this->_takenLiterature;
}

int Client::getTakenLiteratureSize() {
	return this->_takenLiteratureSize;
}

// методы

void Client::addTakenLiterature(ILiterature* takenLiterature) {
	// копируем всю литературу объекта во временный массив temp
	ILiterature** temp = new ILiterature*[this->_takenLiteratureSize];
	for(int i = 0; i < this->_takenLiteratureSize; ++i) {
		temp[i] = this->_takenLiterature[i];
	}
	delete[] this->_takenLiterature;

	// копируем всю литературу из временного массива temp обратно в массив объекта
	this->_takenLiterature = new ILiterature*[this->_takenLiteratureSize+1];
	for(int i = 0; i < this->_takenLiteratureSize; ++i) {
		this->_takenLiterature[i] = temp[i];
	}
	// добавляем новую литературу в конец массива объекта
	this->_takenLiterature[this->_takenLiteratureSize] = takenLiterature;

	this->_takenLiteratureSize++;
	delete[] temp;
}

void Client::deleteTakenLiterature(int takenLiteratureIdx) {
	if (takenLiteratureIdx >= this->_takenLiteratureSize || takenLiteratureIdx < 0) {
		cout << "Error: invalid takenLiteratureIdx was given!" << endl;
		return;
	}
	// копируем всю литературу объекта во временный массив temp
	ILiterature** temp = new ILiterature*[this->_takenLiteratureSize];
	for(int i = 0; i < this->_takenLiteratureSize; ++i) {
		temp[i] = this->_takenLiterature[i];
	}
	delete[] this->_takenLiterature;

	// копируем всю литературу из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_takenLiterature = new ILiterature*[this->_takenLiteratureSize-1];
	for(int i = 0; i < takenLiteratureIdx; ++i) {
		this->_takenLiterature[i] = temp[i];
	}
	for(int i = takenLiteratureIdx+1; i < this->_takenLiteratureSize; ++i) {
		this->_takenLiterature[i-1] = temp[i];
	}

	this->_takenLiteratureSize--;
	delete[] temp;
}

void Client::print(string prefixForSubarray) {
	cout << "Client: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Phone: " << this->getPhone()
		<< " | Came: " << boolalpha << this->getCame()
		<< " | CardID: " << boolalpha << this->_cardId
		<< " | TakenLiterature: ";

	if (this->_takenLiteratureSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_takenLiteratureSize; ++i) {
		cout << prefixForSubarray << "\t" << i << ". ";
		this->_takenLiterature[i]->print(prefixForSubarray + "\t");
	}
}
