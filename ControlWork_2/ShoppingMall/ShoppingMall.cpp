#include <iostream>
#include "./ShoppingMall.h"

using namespace std;

// конструктор
ShoppingMall::ShoppingMall(string title) : _title(title) {
	this->_floors = new Floor*[0];
	this->_floorsSize = 0;
}

// деструктор
ShoppingMall::~ShoppingMall() {
	for(int i = 0; i < this->_floorsSize; ++i) {
		delete this->_floors[i];
	}
	delete[] this->_floors;

	// cout << "___ ~Destr ShoppingMall \"" << this->_title << "\" ___" << endl;
}

// геттеры

string ShoppingMall::getTitle() {
	return this->_title;
}

Floor** ShoppingMall::getFloors() {
	return this->_floors;
}
int ShoppingMall::getFloorsSize() {
	return this->_floorsSize;
}

// сеттеры

void ShoppingMall::setTitle(string title) {
	this->_title = title;
}

// методы

// добавление зала
void ShoppingMall::addFloor(Floor* floor){
	// копируем все залы объекта во временный массив temp
	Floor** temp = new Floor*[this->_floorsSize];
	for(int i = 0; i < this->_floorsSize; ++i) {
		temp[i] = this->_floors[i];
	}
	delete[] this->_floors;

	// копируем все залы из временного массива temp обратно в массив объекта
	this->_floors = new Floor*[this->_floorsSize+1];
	for(int i = 0; i < this->_floorsSize; ++i) {
		this->_floors[i] = temp[i];
	}
	// добавляем новый зал в конец массива объекта
	this->_floors[this->_floorsSize] = floor;

	this->_floorsSize++;
	delete[] temp;
}
// удаление зала
void ShoppingMall::deleteFloor(int floorIdx) {
	if (floorIdx >= this->_floorsSize || floorIdx < 0) {
		cout << "Error: invalid floorIdx was given!" << endl;
		return;
	}
	// копируем все залы объекта во временный массив temp
	Floor** temp = new Floor*[this->_floorsSize];
	for(int i = 0; i < this->_floorsSize; ++i) {
		temp[i] = this->_floors[i];
	}
	delete[] this->_floors;

	// копируем все залы из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_floors = new Floor*[this->_floorsSize-1];
	for(int i = 0; i < floorIdx; ++i) {
		this->_floors[i] = temp[i];
	}
	for(int i = floorIdx+1; i < this->_floorsSize; ++i) {
		this->_floors[i-1] = temp[i];
	}

	this->_floorsSize--;
	delete[] temp;
}

void ShoppingMall::print(string prefix) {
	cout << prefix << "ShoppingMall \"" << this->_title
		<< "\" | Floors amount: " << this->_floorsSize
		<< " | Floors: ";

	// печать этажей
	if (this->_floorsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	for(int i = 0; i < this->_floorsSize; ++i) {
		this->_floors[i]->print(prefix + "\t");
	}
}
