#pragma once
#include <iostream>

using namespace std;


class IHuman {
	public:
		// конструкторы
		IHuman();
		IHuman(string firstName, string lastName, int age, double weight, double height);
		// IHuman(string firstName, string lastName, int age, double weight);
		// IHuman(string firstName, string lastName, int age);
		// IHuman(string firstName, string lastName);
		// IHuman(string firstName);

		// деструкторы
		virtual ~IHuman();

		// сеттеры
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setAge(int age);
		void setWeight(double weight);
		void setHeight(double height);

		// геттеры
		string getFirstName();
		string getLastName();
		int getAge();
		double getWeight();
		double getHeight();

		// методы
		virtual void print() = 0;
		double bodyWeightIndex();
		int bornYear();

	private:
		// поля
		string _firstName;
		string _lastName;
		int _age;
		double _weight;
		double _height;
};
