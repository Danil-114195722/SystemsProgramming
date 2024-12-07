#pragma once
#include <iostream>
#include "./IPerson.h"

using namespace std;


class Client : virtual public IPerson {
	public:
		// конструкторы
		Client(string firstName, string lastName, string phone);

		// деструкторы
		virtual ~Client();

		// геттеры
		string getPhone();

		// методы
		virtual void print(string prefix = "");

	private:
		// поля
		string _phone;
};
