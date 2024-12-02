#pragma once
#include <iostream>
#include "Book.h"
#include "Newspaper.h"

using namespace std;


class Magazine : public Book, Newspaper {
	public:
		// конструкторы
		Magazine(int year, string publisher, string authorFullName, string title, string* themes, int themesSize);
		Magazine();

		// деструкторы
		virtual ~Magazine();

		// методы
		virtual void print(string prefixForSubarray = "");
};
