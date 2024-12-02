#pragma once
#include <iostream>
#include "IVisitor.h"
#include "../../Literature/ILiterature.h"

using namespace std;


class Guest : public IVisitor {
	public:
		// конструкторы
		Guest(string firstName, string lastName, int age, string phone, bool came);
		Guest();

		// деструкторы
		virtual ~Guest();

		// геттеры

		ILiterature** getLiteratureToRead();
		int getLiteratureToReadSize();
		
		// методы
		void addLiteratureToRead(ILiterature* literatureToRead);
		void deleteLiteratureToRead(int literatureToReadIdx);
		
		virtual void print(string prefixForSubarray = "");

	private:
		ILiterature** _literatureToRead;
		int _literatureToReadSize;
};
