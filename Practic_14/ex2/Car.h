#pragma once
#include <iostream>

using namespace std;


class Car {
	public:
		// конструкторы
		Car();
		Car(string brend);
		Car(string brend, string color);
		Car(string brend, string color, string bodyType);
		Car(string brend, string color, string bodyType, double motorCapacity);
		Car(string brend, string color, string bodyType, double motorCapacity, int mileage);

		// деструкторы
		~Car();

		// сеттеры
		void setBrend(string brend);
		void setColor(string color);
		void setBodyType(string bodyType);
		void setMotorCapacity(double motorCapacity);
		void setMileage(int mileage);

		// геттеры
		string getBrend();
		string getColor();
		string getBodyType();
		double getMotorCapacity();
		int getMileage();

		// методы
		void print();
		double averageFuelConsumption();
		int decreaseMileage(int amount);

	private:
		// поля
		string brend;
		string color;
		string bodyType;
		double motorCapacity;
		int mileage;
};
