#include <iostream>
#include "./Theatre.h"

using namespace std;

// конструктор
Theatre::Theatre(string title) : _title(title) {
	this->_halls = new Hall*[0];
	this->_hallsSize = 0;

	this->_plays = new Play*[0];
	this->_playsSize = 0;

	this->_actors = new Actor*[0];
	this->_actorsSize = 0;
}

// деструктор
Theatre::~Theatre() {
	for(int i = 0; i < this->_hallsSize; ++i) {
		delete this->_halls[i];
	}
	delete[] this->_halls;

	for(int i = 0; i < this->_playsSize; ++i) {
		delete this->_plays[i];
	}
	delete[] this->_plays;

	for(int i = 0; i < this->_actorsSize; ++i) {
		delete this->_actors[i];
	}
	delete[] this->_actors;

	// cout << "___ ~Destr Theatre \"" << this->_title << "\" ___" << endl;
}

// геттеры

string Theatre::getTitle() {
	return this->_title;
}

Hall** Theatre::getHalls() {
	return this->_halls;
}
int Theatre::getHallsSize() {
	return this->_hallsSize;
}

Play** Theatre::getPlays() {
	return this->_plays;
}
int Theatre::getPlaysSize() {
	return this->_playsSize;
}

Actor** Theatre::getActors() {
	return this->_actors;
}
int Theatre::getActorsSize() {
	return this->_actorsSize;
}

// сеттеры

void Theatre::setTitle(string title) {
	this->_title = title;
}

// методы

// добавление зала
void Theatre::addHall(Hall* hall){
	// копируем все залы объекта во временный массив temp
	Hall** temp = new Hall*[this->_hallsSize];
	for(int i = 0; i < this->_hallsSize; ++i) {
		temp[i] = this->_halls[i];
	}
	delete[] this->_halls;

	// копируем все залы из временного массива temp обратно в массив объекта
	this->_halls = new Hall*[this->_hallsSize+1];
	for(int i = 0; i < this->_hallsSize; ++i) {
		this->_halls[i] = temp[i];
	}
	// добавляем новый зал в конец массива объекта
	this->_halls[this->_hallsSize] = hall;

	this->_hallsSize++;
	delete[] temp;
}
// удаление зала
void Theatre::deleteHall(int hallIdx) {
	if (hallIdx >= this->_hallsSize || hallIdx < 0) {
		cout << "Error: invalid hallIdx was given!" << endl;
		return;
	}
	// копируем все залы объекта во временный массив temp
	Hall** temp = new Hall*[this->_hallsSize];
	for(int i = 0; i < this->_hallsSize; ++i) {
		temp[i] = this->_halls[i];
	}
	delete[] this->_halls;

	// копируем все залы из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_halls = new Hall*[this->_hallsSize-1];
	for(int i = 0; i < hallIdx; ++i) {
		this->_halls[i] = temp[i];
	}
	for(int i = hallIdx+1; i < this->_hallsSize; ++i) {
		this->_halls[i-1] = temp[i];
	}

	this->_hallsSize--;
	delete[] temp;
}

// добавление спектакля
void Theatre::addPlay(Play* play) {
	// копируем все спектакли объекта во временный массив temp
	Play** temp = new Play*[this->_playsSize];
	for(int i = 0; i < this->_playsSize; ++i) {
		temp[i] = this->_plays[i];
	}
	delete[] this->_plays;

	// копируем все спектакли из временного массива temp обратно в массив объекта
	this->_plays = new Play*[this->_playsSize+1];
	for(int i = 0; i < this->_playsSize; ++i) {
		this->_plays[i] = temp[i];
	}
	// добавляем новый спектакль в конец массива объекта
	this->_plays[this->_playsSize] = play;

	this->_playsSize++;
	delete[] temp;
}
// удаление спектакля
void Theatre::deletePlay(int playIdx) {
	if (playIdx >= this->_playsSize || playIdx < 0) {
		cout << "Error: invalid playIdx was given!" << endl;
		return;
	}
	// копируем все спектакли объекта во временный массив temp
	Play** temp = new Play*[this->_playsSize];
	for(int i = 0; i < this->_playsSize; ++i) {
		temp[i] = this->_plays[i];
	}
	delete[] this->_plays;

	// копируем все спектакли из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_plays = new Play*[this->_playsSize-1];
	for(int i = 0; i < playIdx; ++i) {
		this->_plays[i] = temp[i];
	}
	for(int i = playIdx+1; i < this->_playsSize; ++i) {
		this->_plays[i-1] = temp[i];
	}

	this->_playsSize--;
	delete[] temp;
}

// добавление роли
void Theatre::addActor(Actor* actor) {
	// копируем всех актёров объекта во временный массив temp
	Actor** temp = new Actor*[this->_actorsSize];
	for(int i = 0; i < this->_actorsSize; ++i) {
		temp[i] = this->_actors[i];
	}
	delete[] this->_actors;

	// копируем всех актёров из временного массива temp обратно в массив объекта
	this->_actors = new Actor*[this->_actorsSize+1];
	for(int i = 0; i < this->_actorsSize; ++i) {
		this->_actors[i] = temp[i];
	}
	// добавляем нового актёра в конец массива объекта
	this->_actors[this->_actorsSize] = actor;

	this->_actorsSize++;
	delete[] temp;
}
// удаление роли
void Theatre::deleteActor(int actorIdx) {
	if (actorIdx >= this->_actorsSize || actorIdx < 0) {
		cout << "Error: invalid actorIdx was given!" << endl;
		return;
	}
	// копируем всех актёров объекта во временный массив temp
	Actor** temp = new Actor*[this->_actorsSize];
	for(int i = 0; i < this->_actorsSize; ++i) {
		temp[i] = this->_actors[i];
	}
	delete[] this->_actors;

	// копируем всех актёров из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_actors = new Actor*[this->_actorsSize-1];
	for(int i = 0; i < actorIdx; ++i) {
		this->_actors[i] = temp[i];
	}
	for(int i = actorIdx+1; i < this->_actorsSize; ++i) {
		this->_actors[i-1] = temp[i];
	}

	this->_actorsSize--;
	delete[] temp;
}

void Theatre::print(string prefix) {
	cout << prefix << "Theatre \"" << this->_title
		<< "\" | Halls amount: " << this->_hallsSize
		<< " | Plays amount: " << this->_playsSize
		<< " | Actors amount: " << this->_actorsSize << endl;
}

// печать всех залов
void Theatre::printHalls(string prefix) {
	cout << prefix << "Theatre \"" << this->_title << "\" halls list: "; 
	if (this->_hallsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_hallsSize; ++i) {
		this->_halls[i]->print(prefix + "\t" + to_string(i) + ". ");
	}
}
// печать всех спектаклей
void Theatre::printPlays(string prefix) {
	cout << prefix << "Theatre \"" << this->_title << "\" plays list: ";
	if (this->_playsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_playsSize; ++i) {
		this->_plays[i]->print(prefix + "\t");
	}
}
// печать всех ролей
void Theatre::printActors(string prefix) {
	cout << prefix << "Theatre \"" << this->_title << "\" actors list: ";
	if (this->_actorsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_actorsSize; ++i) {
		this->_actors[i]->print(prefix + "\t" + to_string(i) + ". ");
	}
}

void Theatre::buyTicket(Client* client, int playIdx) {
	if (playIdx >= this->_playsSize || playIdx < 0) {
		cout << "Error: invalid playIdx was given!" << endl;
		return;
	}

	Ticket* newTicket = this->_plays[playIdx]->issueTicket();
	if (newTicket != nullptr) {
		client->addTicket(newTicket);
	}
}
