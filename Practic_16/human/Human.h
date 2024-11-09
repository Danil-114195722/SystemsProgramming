#pragma once
#include <iostream>

using namespace std;


class Human {
	public:
		// конструкторы
		Human();
		Human(string _firstName, string _lastName, int _age, double _weight, double _height);
		Human(string _firstName, string _lastName, int _age, double _weight);
		Human(string _firstName, string _lastName, int _age);
		Human(string _firstName, string _lastName);
		Human(string _firstName);

		// деструкторы
		~Human();

		// перегруз
		Human operator++();
		Human operator--();

		bool operator>(Human other);
		bool operator<(Human other);

		friend ostream& operator<<(ostream& output, Human instance);

		// сеттеры
		void setFirstName(string _firstName);
		void setLastName(string _lastName);
		void setAge(int _age);
		void setWeight(double _weight);
		void setHeight(double _height);

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
		string _firstName;
		string _lastName;
		int _age;
		double _weight;
		double _height;
};
