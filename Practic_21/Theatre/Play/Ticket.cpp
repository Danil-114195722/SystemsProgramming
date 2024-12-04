#include <iostream>
#include "./Ticket.h"

using namespace std;

int Ticket::counter = 0;

// конструктор
Ticket::Ticket(int playId) : _playId(playId) {
	counter++;
	this->_id = counter;
}

// деструктор
Ticket::~Ticket() {
	// cout << "___ ~Destr Ticket " << this->_id << " for play " << this->_playId << " ___" << endl;
}

// сеттеры

void Ticket::setPlayId(int playId) {
	this->_playId = playId;
}

// геттеры

int Ticket::getId() {
	return this->_id;
}

int Ticket::getPlayId() {
	return this->_playId;
}

void Ticket::print(string prefix) {
	cout << prefix << "Ticket: " << this->_id
		<< " | Play ID: " << this->_playId << endl;
}
