#include <iostream>
#include "./Floor.h"

using namespace std;


// конструкторы
Floor::Floor(int number) : _number(number) {
	this->_shops = new Shop*[0];
	this->_shopsSize = 0;
}

// деструктор
Floor::~Floor() {
	for(int i = 0; i < this->_shopsSize; ++i) {
		delete this->_shops[i];
	}
	delete[] this->_shops;

	// cout << "___ ~Destr Floor " << this->_number << " ___" << endl;
}

// геттеры

int Floor::getNumber() {
	return this->_number;
}

Shop** Floor::getShops() {
	return this->_shops;
}
int Floor::getShopsSize() {
	return this->_shopsSize;
}

// методы

void Floor::addShop(Shop* shop) {
	// копируем всех работников объекта во временный массив temp
	Shop** temp = new Shop*[this->_shopsSize];
	for(int i = 0; i < this->_shopsSize; ++i) {
		temp[i] = this->_shops[i];
	}
	delete[] this->_shops;

	// копируем всех работников из временного массива temp обратно в массив объекта
	this->_shops = new Shop*[this->_shopsSize+1];
	for(int i = 0; i < this->_shopsSize; ++i) {
		this->_shops[i] = temp[i];
	}
	// добавляем нового работника в конец массива объекта
	this->_shops[this->_shopsSize] = shop;

	this->_shopsSize++;
	delete[] temp;
}
void Floor::deleteShop(int shopIdx) {
	if (shopIdx >= this->_shopsSize || shopIdx < 0) {
		cout << "Error: invalid shopIdx was given!" << endl;
		return;
	}
	// копируем всех работников объекта во временный массив temp
	Shop** temp = new Shop*[this->_shopsSize];
	for(int i = 0; i < this->_shopsSize; ++i) {
		temp[i] = this->_shops[i];
	}
	delete[] this->_shops;

	// копируем всех работников из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_shops = new Shop*[this->_shopsSize-1];
	for(int i = 0; i < shopIdx; ++i) {
		this->_shops[i] = temp[i];
	}
	for(int i = shopIdx+1; i < this->_shopsSize; ++i) {
		this->_shops[i-1] = temp[i];
	}

	this->_shopsSize--;
	delete[] temp;
}

void Floor::print(string prefix) {
	cout << prefix << "Floor: " << this->_number
		<< " | Shops amount: " << this->_shopsSize 
		<< " | Shops: ";

	// печать магазинов
	if (this->_shopsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	for(int i = 0; i < this->_shopsSize; ++i) {
		this->_shops[i]->print(prefix + "\t");
	}
}
