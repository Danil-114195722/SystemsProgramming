#pragma once
#include <iostream>
#include "IVisitor.h"
#include "../../Literature/ILiterature.h"

using namespace std;


class Client : public IVisitor {
	public:
		// конструкторы
		Client(string firstName, string lastName, int age, string phone, bool came, string cardId, ILiterature** takenLiterature, int takenLiteratureSize);
		Client(string firstName, string lastName, int age, string phone, bool came, string cardId);
		Client();

		// деструкторы
		virtual ~Client();

		// сеттеры
		void setCardId(string cardId);
		
		// геттеры

		string getCardId();
		ILiterature** getTakenLiterature();
		int getTakenLiteratureSize();
		
		// методы
		void addTakenLiterature(ILiterature* takenLiterature);
		void deleteTakenLiterature(int takenLiteratureIdx);
		
		virtual void print(string prefixForSubarray = "");

	private:
		string _cardId;
		ILiterature** _takenLiterature;
		int _takenLiteratureSize;
};
