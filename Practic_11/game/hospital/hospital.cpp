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
	cout << "Проводится лечение. Списано " << heartAmount*oneHeartPrice << " кэша" << endl;
	// добавление сердечек
	health += heartAmount;

	return true;
}
