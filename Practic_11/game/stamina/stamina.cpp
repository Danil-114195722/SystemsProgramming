#include <iostream>
#include <unistd.h>

#include "../main_vars/main_vars.h"
#include "../main_vars/printing.h"
#include "../services/services.h"


// функция траты выносливости
// возвращает true, если выносливость закончилась
bool SpendStamina(int toSpend) {
	stamina -= toSpend;

	if (stamina <= minStamina) {
		cout << "-" << toSpend+stamina << " выносливости" << endl;
		
		stamina = minStamina;
		return true;
	}
	cout << "-" << toSpend << " выносливости" << endl;
	return false;
}


void RecoverStamina() {
	sleep(1);
	PrintState();

	cout << "\nУпс... Выносливость на нуле." << endl;
	cout << "Тебя реанимируют и восстановят немного выносливости. За это придётся заплатить..." << endl;
	sleep(3);
	location = "hospital";

	// снятие минимум 30 кэша за реанимацию
	cash -= 30;

	// если кэша нет, то отнимаем жизнь
	if (cash = -30) {
		cout << "Кэша нет" << endl;
		cout << "-♥" << endl;
		// отнимаем жизнь
		health--;
		// если это была последня жизнь, то игра заканчивается
		if (health == 0) {
			cout << "Здоровье закончилось: ";
            PrintHealth();
            cout << endl;
			gameOver = true;
			return;
		}
	} else if (cash < 0) {
		cout << "-" << 30+cash << " кэша" << endl;
		cash = 0;
	} else {
		cout << "-30 кэша" << endl;
	}

	// восстановление выносливости
	stamina = Randint(30, 50);
	// затраченное время
	age += 1;

	sleep(1);
	cout << "Транспортировка в больницу..." << endl;
}
