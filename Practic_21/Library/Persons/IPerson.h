#pragma once
#include <iostream>

using namespace std;


class IPerson {
	public:
		// конструкторы
		IPerson(string firstName, string lastName, int age);
		IPerson();

		// деструкторы
		virtual ~IPerson();

		// сеттеры
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setAge(int age);

		// геттеры
		string getFirstName();
		string getLastName();
		int getAge();

		// методы
		virtual void print(string prefixForSubarray = "") = 0;

	private:
		// поля
		string _firstName;
		string _lastName;
		int _age;
};