#include <iostream>

#include "../calls/calls.h"
#include "../main_vars/main_vars.h"
#include "../services/services.h"

using namespace std;


// пополнение боекомплекта
// возвращает true, если боекомплект не был полон и пополнился
bool FillAmmunition() {
	if (ammunition == maxAmmunition) {
		cout << "Боекомплект уже полон. Пора выдвигаться на вызов!" << endl;
		return false;
	} else {
		ammunition = maxAmmunition;
		cout << "+ Боекомплект успешно пополнен!" << endl;
		return true;
	}
}


// выдача кол-ва активных вызовов в массиве (предполагается, что он отсортирован функцией RecollectCallList из ../calls/calls.h)
int ActiveCallsCount(Call* callList) {
	for (int i = 0; i < 9; ++i) {
		if (!(callList[i].isOccupied)) {
			return i;
		}
	}
	return 9;
}


// выдача рандомного кол-ва новых вызовов (от 0 до 2)
void CreateCalls(Call* callList) {
	int activeCalls = ActiveCallsCount(callList);

	// если в массиве активных вызовов нет
	if (activeCalls == 0) {
		GetRandomCall(&(callList[0]));
		cout << "+ Поступило сообщение о новом вызове!" << endl;
		// выдача второго вызова (20%)
		if (Randint(1, 100) >= 80) {
			GetRandomCall(&(callList[1]));
			cout << "+ Поступило сообщение о новом вызове!" << endl;
		}
	// если массив активных вызовов заполнен полностью
	} else if (activeCalls == 9) {
		return;
	// если массив активных вызовов вместит только 1 новый вызов
	} else if (activeCalls == 8) {
		// выдача нового вызова (5%)
		if (Randint(1, 100) >= 95) {
			GetRandomCall(&(callList[activeCalls]));
			cout << "+ Поступило сообщение о новом вызове!" << endl;
		}
	// если массив активных вызовов может вместить 2 новых вызова
	} else {
		int* randCallsCountPercent = new int;
		*randCallsCountPercent = Randint(1, 100);

		// если *randCallsCountPercent <= 30, то новый вызов не выдаётся (30%)
		// выдача 1 нового вызова (45%)
		if (*randCallsCountPercent > 30 && *randCallsCountPercent <= 75) {
			GetRandomCall(&(callList[activeCalls]));
			cout << "+ Поступило сообщение о новом вызове!" << endl;
		// выдача 2 новых вызовов (25%)
		} else if (*randCallsCountPercent > 75) {
			GetRandomCall(&(callList[activeCalls]));
			GetRandomCall(&(callList[activeCalls+1]));
			cout << "+ Поступило сообщение о двух новых вызовах!" << endl;
		}

		delete randCallsCountPercent;
	}
}
