#pragma once
#include <iostream>

using namespace std;


class Human {
	public:
		// конструкторы
		Human() = default;
		Human(string firstName);
		Human(string firstName, string lastName);
		Human(string firstName, string lastName, int age);
		Human(string firstName, string lastName, int age, double weight);
		Human(string firstName, string lastName, int age, double weight, double height);

		// деструкторы
		~Human();

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
		void print();
		double bodyWeightIndex();
		int bornYear();

	private:
		// поля
		string firstName;
		string lastName;
		int age;
		double weight;
		double height;
};
