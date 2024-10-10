#include <iostream>
#include <unistd.h>

#include "./calls/calls.h"
#include "./location/location.h"
#include "./main_vars/main_vars.h"

using namespace std;


int main() {
	// вывод приглашения игры и её краткого описания
	DisplayIntro();
	if (gameOver) {
		cout << "Хорошо, приходи в другой раз" << endl;
		return 0;
	} else {
		cout << "Начинаем..." << endl << endl;
	}

	// получение нескольких вызовов
	Call newCall1;
	GetRandomCall(&newCall1);
	Call newCall2;
	GetRandomCall(&newCall2);
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
	while(age < pensionAge) {
		// печать текущей локации и доступных действий
		CurrentLocation(callList, chosenCallIdx);

		// запрос действия в соответствии с локацией и выполнения действия
		chosenCallIdx = MakeAction(callList, chosenCallIdx);
		// если персонаж погиб
		if (gameOver) {
			break;
		}
		sleep(1);
	}

	// если игра окончена, печатаем GAME OVER
	if (gameOver) {
		cout << "\nGAME OVER" << endl;
	// если мент достиг "пенсионного возраста", то высчитываем концовку
	} else {
		DisplayPensionEnd();
	}

	return 0;
}
