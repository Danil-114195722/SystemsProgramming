#pragma once
#include <iostream>
#include "Car.h"

using namespace std;


class PassangerCar : public Car {
	public:
		// конструкторы
		PassangerCar();
		PassangerCar(string _brend, string _color, string _bodyType, double _motorCapacity, int _mileage, bool _hasArmrest);
		PassangerCar(string _brend, string _color, string _bodyType, double _motorCapacity, int _mileage);
		PassangerCar(string _brend, string _color, string _bodyType, double _motorCapacity);
		PassangerCar(string _brend, string _color, string _bodyType);
		PassangerCar(string _brend, string _color);
		PassangerCar(string _brend);

		// геттеры и сеттеры
		void setHasArmrest(bool hasArmrest);
		bool getHasArmrest();

		// методы
		void displayPassangerCar();

	private:
		bool _hasArmrest;
};
