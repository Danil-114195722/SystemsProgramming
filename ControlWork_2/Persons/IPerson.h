#pragma once
#include <iostream>

using namespace std;


class IPerson {
	public:
		// конструкторы
		IPerson(string firstName, string lastName);

		// деструкторы
		virtual ~IPerson();

		// геттеры
		string getFirstName();
		string getLastName();

		// методы
		virtual void print(string prefix = "") = 0;

	private:
		// поля
		string _firstName;
		string _lastName;
};
