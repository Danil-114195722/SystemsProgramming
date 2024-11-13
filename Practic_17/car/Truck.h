#pragma once
#include <iostream>
#include "Car.h"

using namespace std;


class Truck : public Car {
	public:
		// конструкторы
		Truck();
		Truck(string _brend, string _color, string _bodyType, double _motorCapacity, int _mileage, bool _hasTrailer);
		Truck(string _brend, string _color, string _bodyType, double _motorCapacity, int _mileage);
		Truck(string _brend, string _color, string _bodyType, double _motorCapacity);
		Truck(string _brend, string _color, string _bodyType);
		Truck(string _brend, string _color);
		Truck(string _brend);

		// геттеры и сеттеры
		void setHasTrailer(bool hasTrailer);
		bool getHasTrailer();

		// методы
		void displayTruck();

	private:
		bool _hasTrailer;
};
