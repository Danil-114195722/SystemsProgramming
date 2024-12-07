#pragma once
#include <iostream>
#include "../Shop/Shop.h"

using namespace std;


class Floor {
	public:
		// конструкторы
		Floor(int number);

		// деструкторы
		~Floor();

		// геттеры
		int getNumber();

		Shop** getShops();
		int getShopsSize();
		
		// методы
		void addShop(Shop* shop);
		void deleteShop(int shopIdx);

		void print(string prefix = "");

	private:
		// поля
		int _number;

		Shop** _shops;
		int _shopsSize;
};
