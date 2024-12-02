#pragma once
#include <iostream>

using namespace std;

// BOOK:
// string _authorFullName;
// string _title;
// string _genre;

// NEWSPAPER:
// string* _themes;
// int _themesSize;

// MAGAZINE:
// (BOOK) string _authorFullName;
// (BOOK) string _title;
// (NEWSPAPER) string* _themes;
// (NEWSPAPER) int _themesSize;


class ILiterature {
	public:
		// конструкторы
		ILiterature(int year, string publisher);
		ILiterature();

		// деструкторы
		virtual ~ILiterature();

		// сеттеры
		void setYear(int year);
		void setPublisher(string publisher);

		// геттеры
		int getYear();
		string getPublisher();

		// методы
		virtual void print(string prefixForSubarray = "") = 0;

	private:
		// поля
		int _year;
		string _publisher;
};
