#pragma once
#include <iostream>
#include "ILiterature.h"

using namespace std;


class Book : virtual public ILiterature {
	public:
		// конструкторы
		Book(int year, string publisher, string authorFullName, string title, string genre);
		Book(string authorFullName, string title);
		Book();

		// деструкторы
		virtual ~Book();

		// сеттеры
		
		void setAuthorFullName(string post);
		void setTitle(string title);
		void setGenre(string genre);
		
		// геттеры
		
		string getAuthorFullName();
		string getTitle();
		string getGenre();

		// методы
		virtual void print(string prefixForSubarray = "");

	private:
		string _authorFullName;
		string _title;
		string _genre;
};
