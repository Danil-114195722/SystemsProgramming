#pragma once
#include <iostream>
#include "../IPerson.h"

using namespace std;


class IVisitor : public IPerson {
	public:
		// конструкторы
		IVisitor(string firstName, string lastName, int age, string phone, bool came);
		IVisitor();

		// деструкторы
		virtual ~IVisitor();

		// сеттеры
		
		void setPhone(string phone);
		void setCame(bool came);

		// геттеры

		string getPhone();
		bool getCame();

		// методы
		virtual void print(string prefixForSubarray = "") = 0;

	private:
		string _phone;
		bool _came;
};
