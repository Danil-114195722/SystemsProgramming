#pragma once
#include <iostream>
#include "./Floor.h"

using namespace std;


class ShoppingMall {
	public:
		// конструктор
		ShoppingMall(string title);

		// деструкторы
		~ShoppingMall();

		// геттеры
		string getTitle();

		Floor** getFloors();
		int getFloorsSize();
		
		// сеттеры
		void setTitle(string title);

		// методы
		void addFloor(Floor* floor);
		void deleteFloor(int floorIdx);

		void print(string prefix = "");

	private:
		// поля
		string _title;
		
		Floor** _floors;
		int _floorsSize;
};
