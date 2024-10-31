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

		// перегруз
		Human operator++();
		Human operator--();

		bool operator>(Human other);
		bool operator<(Human other);

		friend ostream& operator<<(ostream& output, Human instance);

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
