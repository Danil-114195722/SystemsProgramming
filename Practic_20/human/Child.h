#pragma once
#include <iostream>
#include "Human.h"

using namespace std;


class Child : virtual public IHuman {
	public:
		// конструкторы
		Child(string firstName, string lastName, int age, double weight, double height, string studyPlace);
		Child(string studyPlace);
		Child();

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
		virtual void readFromConsole();
		virtual void writeToFile();
		virtual void print();

	private:
		string _studyPlace;
};
