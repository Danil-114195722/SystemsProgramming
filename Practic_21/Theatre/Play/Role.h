#pragma once
#include <iostream>
#include "../Persons/Actor.h"

using namespace std;


class Role {
	public:
		// конструкторы
		Role(string title, string nickname, int age, Actor* actor);
		Role();

		// деструкторы
		~Role();

		// геттеры
		string getTitle();
		string getNickname();
		int getAge();
		Actor* getActor();

		// сеттеры

		void setTitle(string title);
		void setNickname(string nickname);
		void setAge(int age);
		void setActor(Actor* actor);

		// методы
		void print(string prefix = "");

	private:
		// поля
		string _title;
		string _nickname;
		int _age;
		Actor* _actor;
};
