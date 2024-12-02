#pragma once
#include <iostream>
#include "ILiterature.h"

using namespace std;


class Newspaper : virtual public ILiterature {
	public:
		// конструкторы
		Newspaper(int year, string publisher, string* themes, int themesSize);
		Newspaper(string* themes, int themesSize);
		Newspaper();

		// деструкторы
		virtual ~Newspaper();

		// сеттеры
		
		void setThemes(string* themes, int themesSize);
		
		// геттеры
		
		string* getThemes();
		int getThemesSize();

		// методы
		virtual void print(string prefixForSubarray = "");

	private:
		string* _themes;
		int _themesSize;
};
