#include <iostream>
#include "VendingMachine.h"

using namespace std;


VendingMachine::VendingMachine(int snackSlotsSize) : _snackSlotsSize(snackSlotsSize) {
	this->_snackSlots = new SnackSlot*[snackSlotsSize];
	this->_snackSlotsAmount = 0;
}

// деструктор
VendingMachine::~VendingMachine() {
	delete[] this->_snackSlots;
	// cout << "__ ~Destr VendingMachine __" << endl;
}

int VendingMachine::getEmptySlotsCount() {
	return this->_snackSlotsSize - this->_snackSlotsAmount;
}

void VendingMachine::addSlot(SnackSlot* snackSlot) {
	if (this->_snackSlotsAmount == this->_snackSlotsSize) {
		cout << "Error! Cannot add snack slot to vending machine. Vending machine is full." << endl;
		return;
	}
	this->_snackSlots[this->_snackSlotsAmount] = snackSlot;
	this->_snackSlotsAmount++;
}

Snack* VendingMachine::issueSnack(int snackSlotIdx) {
	if (snackSlotIdx < 0 || snackSlotIdx >= this->_snackSlotsAmount) {
		cout << "Error! Cannot issue snack from vending machine. Invalid snack slot index was given." << endl;
		return nullptr;
	}
	Snack* snackToIssue = this->_snackSlots[snackSlotIdx]->issueSnack();
	if (snackToIssue == nullptr) {
		cout << "Error! Cannot issue snack from vending machine. Snack slot is empty." << endl;
	}
	return snackToIssue;
}

void VendingMachine::print() {
	cout << "VendingMachine"
		<< " | Free place for snack slots: " << this->_snackSlotsSize - this->_snackSlotsAmount
		<< " | Snack slots: ";

	// печать слотов для батончиков, если такие есть
	if (this->_snackSlotsAmount != 0) {
		cout << endl;
		for(int i = 0; i < this->_snackSlotsAmount; ++i) {
			cout << "\t" << i << ". ";
			this->_snackSlots[i]->print();
		}
	} else {
		cout << "no one" << endl;
	}
}
