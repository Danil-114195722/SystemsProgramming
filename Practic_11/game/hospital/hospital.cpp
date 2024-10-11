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
	// считывание выносливости за лечение

	// TODO: уменьшение выносливости на 10 за каждое восстановленное сердечко (heartAmount*10)

	cout << "Проводится лечение..." << endl;
	cout << "-" << heartAmount*oneHeartPrice << " кэша" << endl;
	cout << "-" << heartAmount*10 << " выносливости" << endl;
	// добавление сердечек
	health += heartAmount;

	return true;
}
