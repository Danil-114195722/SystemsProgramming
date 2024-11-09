#pragma once
#include <iostream>

using namespace std;


class Animal {
	public:
		// конструкторы
		Animal();
		Animal(string name, string species, string color, int age, double weight);
		Animal(string name, string species, string color, int age);
		Animal(string name, string species, string color);
		Animal(string name, string species);
		Animal(string name);

		// деструкторы
		~Animal();

		// перегруз
		Animal operator++();
		Animal operator--();

		bool operator>(Animal other);
		bool operator<(Animal other);

		friend ostream& operator<<(ostream& output, Animal instance);

		// сеттеры
		void setName(string name);
		void setSpecies(string species);
		void setColor(string color);
		void setAge(int age);
		void setWeight(double weight);

		// геттеры
		string getName();
		string getSpecies();
		string getColor();
		int getAge();
		double getWeight();

		// методы
		void print();
		double feed(int days);
		string changeName(string newName);

	private:
		// поля
		string _name;
		string _species;
		string _color;
		int _age;
		double _weight;
};
