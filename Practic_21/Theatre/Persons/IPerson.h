#pragma once
#include <iostream>

using namespace std;


class IPerson {
	public:
		// конструкторы
		IPerson(string firstName, string lastName);
		IPerson();

		// деструкторы
		virtual ~IPerson();

		// сеттеры
		void setFirstName(string firstName);
		void setLastName(string lastName);

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
