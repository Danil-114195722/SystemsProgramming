#include <iostream>
#include "./classes/Snack.h"
#include "./classes/SnackSlot.h"
#include "./classes/VendingMachine.h"


int main(){
	Snack* bounty = new Snack("Bounty", 484, 0.9);
	Snack* snickers = new Snack("Snickers", 491, 0.67);
	bounty->print();
	snickers->print();

	// количество батончиков, которые помещаются в слот
	SnackSlot *slot = new SnackSlot(10);
	slot->print();

	// добавляем батончики в слот
	slot->addSnack(bounty);
	slot->addSnack(snickers);
	slot->print();
	
	// количество слотов для снеков
	VendingMachine* machine = new VendingMachine(3);
	machine->print();
	
	// помещаем слот в аппарат
	machine->addSlot(slot);
	machine->print();

	Snack* snack1 = machine->issueSnack(0);
	snack1->print();
	machine->print();

	// должно выводить количество пустых слотов для снеков
	cout << "EmptySlotsCount: " << machine->getEmptySlotsCount() << endl;

	delete machine;
	delete snickers;
	delete bounty;
	delete slot;

	return 0;
}
