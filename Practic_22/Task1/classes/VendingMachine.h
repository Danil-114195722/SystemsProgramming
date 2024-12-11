#pragma once
#include <iostream>
#include "./Snack.h"
#include "./SnackSlot.h"

using namespace std;


class VendingMachine {
	public:
		VendingMachine(int snackSlotsSize);
		~VendingMachine();

		int getEmptySlotsCount();

		void addSlot(SnackSlot* snack);
		Snack* issueSnack(int snackSlotIdx);

		void print();

	private:
		SnackSlot** _snackSlots;
		int _snackSlotsSize;
		int _snackSlotsAmount;
};
