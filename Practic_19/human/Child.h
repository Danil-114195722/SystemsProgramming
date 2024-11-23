#pragma once
#include <iostream>
#include "Human.h"

using namespace std;


class Child : public IHuman {
	public:
		// конструкторы
		Child();
		Child(string firstName, string lastName, int age, double weight, double height, string studyPlace);
		Child(string firstName, string lastName, int age, double weight, double height);
		Child(string firstName, string lastName, int age, double weight);
		Child(string firstName, string lastName, int age);
		Child(string firstName, string lastName);
		Child(string firstName);

		// деструкторы
		~Child();

		// перегруз
		Child operator++();
		Child operator--();

		bool operator>(Child other);
		bool operator<(Child other);

		friend ostream& operator<<(ostream& output, Child instance);

		// геттеры и сеттеры
		void setStudyPlace(string studyPlace);
		string getStudyPlace();

		// методы
		void print();

	private:
		string _studyPlace;
};
