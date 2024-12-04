#pragma once
#include <iostream>

using namespace std;


class Hall {
	public:
		// конструкторы
		Hall(int number, int placeAmount);
		Hall();

		// деструкторы
		~Hall();

		// геттеры
		int getNumber();
		int getPlaceAmount();

		// сеттеры

		void setNumber(int number);
		void setPlaceAmount(int placeAmount);

		// методы
		void print(string prefix = "");

	private:
		// поля
		int _number;
		int _placeAmount;
};
