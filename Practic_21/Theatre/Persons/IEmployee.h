#pragma once
#include <iostream>
#include "./IPerson.h"

using namespace std;


class IEmployee : virtual public IPerson {
	public:
		// конструкторы
		IEmployee(string firstName, string lastName, int age, int experience);
		IEmployee();

		// деструкторы
		virtual ~IEmployee();

		// сеттеры
		
		void setAge(int age);
		void setExperience(int experience);
		
		// геттеры

		int getAge();
		int getExperience();

		// методы
		virtual void print(string prefix = "") = 0;

	private:
		int _age;
		int _experience;
};
