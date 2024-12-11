#include <iostream>
#include "./classes/Snack.h"
#include "./classes/SnackSlot.h"
#include "./classes/VendingMachine.h"


int main(){
	Snack* bounty = new Snack("Bounty", 484, 0.9);
	Snack* snickers = new Snack("Snickers", 491, 0.67);
	Snack* mars = new Snack("Mars", 457, 0.7);
	Snack* twix = new Snack("Twix", 494, 0.63);
	bounty->print();
	snickers->print();

	// количество батончиков, которые помещаются в слот
	SnackSlot *slot = new SnackSlot(10);
	// добавляем батончики в слот
	for (int i = 0; i < 4; ++i) {
		slot->addSnack(bounty);
	}

	SnackSlot *slot2 = new SnackSlot(10);
	for (int i = 0; i < 2; ++i) {
		slot2->addSnack(snickers);
	}

	SnackSlot *slot3 = new SnackSlot(10);
	for (int i = 0; i < 5; ++i) {
		slot3->addSnack(mars);
	}

	SnackSlot *slot4 = new SnackSlot(10);
	for (int i = 0; i < 11; ++i) {
		slot4->addSnack(twix);
	}
	
	// количество слотов для снеков
	VendingMachine* machine = new VendingMachine(3);
	machine->print();

	// должно выводить количество пустых слотов для снеков
	cout << "EmptySlotsCount: " << machine->getEmptySlotsCount() << endl;

	// помещаем слоты в аппарат
	machine->addSlot(slot);
	machine->addSlot(slot3);
	machine->addSlot(slot4);
	machine->addSlot(slot2);
	machine->print();

	Snack* snack1 = machine->issueSnack(0);
	snack1->print();
	machine->print();

	Snack* snack2 = machine->issueSnack(2);
	snack2->print();
	machine->print();

	cout << "EmptySlotsCount: " << machine->getEmptySlotsCount() << endl;

	delete machine;
	
	delete twix;
	delete mars;
	delete snickers;
	delete bounty;
	
	delete slot;
	delete slot2;
	delete slot3;
	delete slot4;

	return 0;
}
