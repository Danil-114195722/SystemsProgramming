#pragma once
#include <iostream>

using namespace std;


class Ticket {
	static int counter;

	public:
		// конструктор
		Ticket(int playId);

		// деструкторы
		~Ticket();

		// сеттеры
		void setPlayId(int playId);

		// геттеры
		int getId();
		int getPlayId();

		// методы
		void print(string prefix = "");

	private:
		// поля
		int _id;
		int _playId;
};
