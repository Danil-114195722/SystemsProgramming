#include <iostream>
#include "SnackSlot.h"

using namespace std;


SnackSlot::SnackSlot(int snacksSize) : _snacksSize(snacksSize) {
	this->_snacks = new Snack*[snacksSize];
	this->_snacksAmount = 0;
}

// деструктор
SnackSlot::~SnackSlot() {
	delete[] this->_snacks;
	// cout << "__ ~Destr SnackSlot __" << endl;
}

void SnackSlot::addSnack(Snack* snack) {
	if (this->_snacksAmount == this->_snacksSize) {
		cout << "Error! Cannot add snack to snack slot. Snack slot is full." << endl;
		return;
	}
	this->_snacks[this->_snacksAmount] = snack;
	this->_snacksAmount++;
}

Snack* SnackSlot::issueSnack() {
	if (this->_snacksAmount == 0) {
		cout << "Error! Cannot issue snack from snack slot. Snack slot is empty." << endl;
		return nullptr;
	}
	this->_snacksAmount--;
	return this->_snacks[this->_snacksAmount];
}

void SnackSlot::print() {
	cout << "SnackSlot"
		<< " | Free place for snacks: " << this->_snacksSize - this->_snacksAmount
		<< " | Snacks in slot: " << this->_snacksAmount;

	// печать последнего батончика, если такой есть
	if (this->_snacksAmount != 0) {
		cout << " | Last ";
		this->_snacks[this->_snacksAmount-1]->print();
	} else {
		cout << endl;
	}
}
