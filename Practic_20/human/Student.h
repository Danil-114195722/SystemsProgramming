#pragma once
#include <iostream>
#include "Child.h"
#include "Adult.h"

using namespace std;


class Student : public Child, Adult {
	public:
		// конструкторы
		Student();
		Student(string firstName, string lastName, int age, double weight, double height, string studyPlace, string workPlace, string livePlace);

		// деструкторы
		~Student();

		// перегруз
		Student operator++();
		Student operator--();

		bool operator>(Student other);
		bool operator<(Student other);

		friend ostream& operator<<(ostream& output, Student instance);

		// геттеры и сеттеры
		void setLivePlace(string livePlace);
		string getLivePlace();

		// методы
		void readFromConsole();
		void writeToFile();
		void print();

	private:
		string _livePlace;
};
