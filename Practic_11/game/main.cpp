#include <iostream>
#include <unistd.h>

#include "./calls/calls.h"
#include "./shop/shop.h"
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

	// список для вызовов
	struct Call callList[9];
	// заполнение массива пустыми вызовами
	Call emptyCall;
	emptyCall.isOccupied = false;
	for (int i = 3; i < 9; ++i) {
		callList[i] = emptyCall;
	}
	// получение нескольких случайных вызовов
	GetRandomCall(&(callList[0]));
	GetRandomCall(&(callList[1]));
	GetRandomCall(&(callList[2]));

	// список для продуктов
	struct Product productList[3];
	// получение трёх новых случайных продуктов
	GetRandomProducts(productList, 3);

	// индекс выбранного вызова
	int chosenCallIdx = 0;
	while(age <= pensionAge) {
		// печать текущей локации и доступных действий
		CurrentLocation(callList, chosenCallIdx, productList);

		// запрос действия в соответствии с локацией и выполнения действия
		chosenCallIdx = MakeAction(callList, chosenCallIdx, productList);
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
