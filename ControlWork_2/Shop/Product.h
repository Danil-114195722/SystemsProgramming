#pragma once
#include <iostream>

using namespace std;


class Product {
	public:
		// конструктор
		Product(string title, string manufacturer, string manufacturerCountry);

		// деструкторы
		~Product();

		// геттеры
		string getTitle();
		string getManufacturer();
		string getManufacturerCountry();

		// методы
		void print(string prefix = "");

	private:
		// поля
		string _title;
		string _manufacturer;
		string _manufacturerCountry;
};
