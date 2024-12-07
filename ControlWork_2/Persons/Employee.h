#pragma once
#include <iostream>
#include "./IPerson.h"

using namespace std;


class Employee : virtual public IPerson {
	public:
		// конструкторы
		Employee(string firstName, string lastName, int age, int experience, int salary);

		// деструкторы
		virtual ~Employee();

		// геттеры

		int getAge();
		int getExperience();
		int getSalary();

		// методы
		virtual void print(string prefix = "");

	private:
		int _age;
		int _experience;
		int _salary;
};
