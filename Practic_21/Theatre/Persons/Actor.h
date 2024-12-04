#pragma once
#include <iostream>
#include "./IEmployee.h"

using namespace std;


class Actor : public IEmployee {
	public:
		// конструкторы
		Actor(string firstName, string lastName, int age, int experience, string gender, string education);
		Actor();

		// деструкторы
		virtual ~Actor();

		// сеттеры

		void setGender(string gender);
		void setEducation(string education);

		// геттеры

		string getGender();
		string getEducation();

		// методы
		virtual void print(string prefix = "");

	private:
		string _gender;
		string _education;
};
