#pragma once
#include <iostream>

using namespace std;


namespace human {
	enum age {
		sampleBaby = 3,
		sampleYoung = 18,
		sampleMiddle = 33,
		sampleOld = 66,
	};
}


class IHuman {
	public:
		// конструкторы
		IHuman(string firstName, string lastName, int age, double weight, double height);
		IHuman();

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
		virtual void readFromConsole();
		virtual void writeToFile() = 0;
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
