#include <iostream>
#include "./Role.h"

using namespace std;


// конструкторы
Role::Role(string title, string nickname, int age, Actor* actor) : _title(title), _nickname(nickname), _age(age), _actor(actor) {}
Role::Role() : _title("-"), _nickname("-"), _age(0) {
	this->_actor = new Actor();
}

// деструктор
Role::~Role() {
	// cout << "___ ~Destr Role " << this->_title << " " << this->_nickname << " ___" << endl;
}

// геттеры

string Role::getTitle() {
	return this->_title;
}
string Role::getNickname() {
	return this->_nickname;
}
int Role::getAge() {
	return this->_age;
}
Actor* Role::getActor() {
	return this->_actor;
}

// сеттеры

void Role::setTitle(string title) {
	this->_title = title;
}
void Role::setNickname(string nickname) {
	this->_nickname = nickname;
}
void Role::setAge(int age) {
	this->_age = age;
}
void Role::setActor(Actor* actor) {
	this->_actor = actor;
}

// методы

void Role::print(string prefix) {
	cout << prefix << "Role: " << this->_title
		<< " | Nickname: " << this->_nickname
		<< " | Age: " << this->_age
		<< " | Actor: " << endl;
	this->_actor->print(prefix + "\t");
}
