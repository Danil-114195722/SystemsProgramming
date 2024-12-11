#pragma once
#include <iostream>

using namespace std;


class Snack {
	public:
		Snack(string title, double calories, double price);
		~Snack();

		string getTitle();
		double getCalories();
		double getPrice();

		void setNewPrice(double price);
		void print();

	private:
		string _title;
		double _calories;
		double _price;
};
