#include <iostream>
#include <unistd.h>

#include "./calls/calls.h"
// #include "./calls/printing.h"

// #include "./main_vars/main_vars.h"
// #include "./main_vars/printing.h"

#include "./location/location.h"

using namespace std;


int main() {
	// вывод приглашения игры и её краткого описания
	DisplayIntro();

	// получение нескольких вызовов
	sleep(1);
	Call newCall1;
	GetRandomCall(&newCall1);
	sleep(1);
	Call newCall2;
	GetRandomCall(&newCall2);
	sleep(1);
	Call newCall3;
	GetRandomCall(&newCall3);

	// список для вызовов
	struct Call callList[9] = {newCall1, newCall2, newCall3};
	// заполнение оставшихся элементов массива пустыми вызовами
	Call emptyCall;
	emptyCall.isOccupied = false;
	for (int i = 3; i < 9; ++i) {
		callList[i] = emptyCall;
	}

	// индекс выбранного вызова
	int chosenCallIdx = 0;
	while(true) {
		// печать текущей локации и доступных действий
		CurrentLocation(callList, chosenCallIdx);

		// запрос действия в соответствии с локацией и выполнения действия
		chosenCallIdx = MakeAction(callList);
		sleep(1);
	}

	// // чистка массива вызовов от выполненного вызова
	// RecollectCallList(callList, 1);

	// // печать текущей локации и доступных действий
	// CurrentLocation(callList, 0);

	// cout << endl;
	// PrintShortCall(newCall);
	// cout << endl;
	// PrintFullCall(newCall);

	// bool res = PerformCall(newCall);

	// cout << "\nPerformed: " << boolalpha << res << endl;
	// PrintState();

	return 0;
}
