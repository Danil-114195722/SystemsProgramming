#pragma once
#include <iostream>
#include "IPerson.h"

using namespace std;


class Employee : public IPerson {
	public:
		// конструкторы
		Employee(string firstName, string lastName, int age, string post);
		Employee();

		// деструкторы
		virtual ~Employee();

		// геттеры и сеттеры
		void setPost(string post);
		string getPost();

		// методы
		virtual void print(string prefixForSubarray = "");

	private:
		string _post;
};
