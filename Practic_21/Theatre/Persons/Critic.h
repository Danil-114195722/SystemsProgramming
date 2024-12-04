#pragma once
#include <iostream>
#include "./IEmployee.h"
#include "./Client.h"

using namespace std;


class Critic : public IEmployee, public Client {
	public:
		// конструкторы
		Critic(string firstName, string lastName, int age, int experience);
		Critic();

		// деструкторы
		virtual ~Critic();

		// методы
		virtual void print(string prefix = "");
};
