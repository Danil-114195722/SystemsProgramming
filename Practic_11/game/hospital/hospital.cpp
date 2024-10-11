#include <iostream>
#include "../main_vars/main_vars.h"


// лечение heartAmount кол-ва жизней
bool Heal(int heartAmount) {
	// если не хватает кэша
	if (heartAmount*oneHeartPrice > cash) {
		return false;
	}
	// считывание кэша за лечение
	cash -= heartAmount*oneHeartPrice;

	cout << "Проводится лечение..." << endl;
	cout << "-" << heartAmount*oneHeartPrice << " кэша" << endl;
	// добавление сердечек
	health += heartAmount;

	return true;
}
