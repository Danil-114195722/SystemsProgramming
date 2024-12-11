#pragma once
#include <iostream>
#include "./Snack.h"

using namespace std;


class SnackSlot {
	public:
		SnackSlot(int snacksSize);
		~SnackSlot();

		void addSnack(Snack* snack);
		Snack* issueSnack();

		void print();

	private:
		Snack** _snacks;
		int _snacksSize;
		int _snacksAmount;
};
