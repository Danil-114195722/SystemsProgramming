#pragma once
#include <iostream>

using namespace std;


class Car {
	public:
		// конструкторы
		Car();
		Car(string brend, string color, string bodyType, double motorCapacity, int mileage);
		Car(string brend, string color, string bodyType, double motorCapacity);
		Car(string brend, string color, string bodyType);
		Car(string brend, string color);
		Car(string brend);

		// деструкторы
		~Car();

		// перегруз
		Car operator++();
		Car operator--();

		bool operator>(Car other);
		bool operator<(Car other);

		friend ostream& operator<<(ostream& output, Car instance);

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
		double averageFuelConsumption();
		int decreaseMileage(int amount);

	private:
		// поля
		string _brend;
		string _color;
		string _bodyType;
		double _motorCapacity;
		int _mileage;
};
