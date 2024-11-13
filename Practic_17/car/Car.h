#pragma once
#include <iostream>

using namespace std;


class Car {
	public:
		// конструкторы
		Car();
		Car(string _brend, string _color, string _bodyType, double _motorCapacity, int _mileage);
		Car(string _brend, string _color, string _bodyType, double _motorCapacity);
		Car(string _brend, string _color, string _bodyType);
		Car(string _brend, string _color);
		Car(string _brend);

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
