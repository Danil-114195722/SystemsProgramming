#pragma once
#include <iostream>
#include "./Employee.h"
#include "./Client.h"

using namespace std;


class Inspector : public Employee, public Client {
	public:
		// конструкторы
		Inspector(string firstName, string lastName, string phone, int age, int experience);

		// деструкторы
		virtual ~Inspector();

		// методы
		virtual void print(string prefix = "");
};
