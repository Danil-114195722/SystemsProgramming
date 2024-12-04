#include <iostream>
#include "./Play.h"

using namespace std;

int Play::counter = 0;

// конструктор
Play::Play(string title, string date, Hall* hall, Role** roles, int rolesSize) : _title(title), _date(date), _hall(hall) {
	counter++;
	this->_id = counter;

	// добавление ролей
	this->_roles = new Role*[rolesSize];
	this->_rolesSize = rolesSize;

	for(int i = 0; i < rolesSize; ++i) {
		this->_roles[i] = roles[i];
	}

	// создание билетов в соответствии с кол-вом мест в зале
	this->_ticketsSize = this->_hall->getPlaceAmount();
	this->_tickets = new Ticket*[this->_ticketsSize];

	for(int i = 0; i < this->_ticketsSize; ++i) {
		this->_tickets[i] = new Ticket(this->_id);
	}
	// кол-во выданных билетов
	this->_issuedTickets = 0;
}

// деструктор
Play::~Play() {
	for(int i = 0; i < this->_rolesSize; ++i) {
		delete this->_roles[i];
	}
	delete[] this->_roles;

	for(int i = 0; i < this->_ticketsSize; ++i) {
		delete this->_tickets[i];
	}
	delete[] this->_tickets;

	// cout << "___ ~Destr Play " << this->_title << " ___" << endl;
}

// геттеры

int Play::getId() {
	return this->_id;
}
string Play::getTitle() {
	return this->_title;
}
string Play::getDate() {
	return this->_date;
}
Hall* Play::getHall() {
	return this->_hall;
}
Role** Play::getRoles() {
	return this->_roles;
}
int Play::getRolesSize() {
	return this->_rolesSize;
}
int Play::getIssuedTickets() {
	return this->_issuedTickets;
}

// сеттеры

void Play::setTitle(string title) {
	this->_title = title;
}
void Play::setDate(string date) {
	this->_date = date;
}
void Play::setHall(Hall* hall) {
	this->_hall = hall;
}
void Play::setRoles(Role** roles, int rolesSize) {
	delete[] this->_roles;

	this->_roles = new Role*[rolesSize];
	this->_rolesSize = rolesSize;

	for(int i = 0; i < rolesSize; ++i) {
		this->_roles[i] = roles[i];
	}
}

// методы

Ticket* Play::issueTicket() {
	if (this->_issuedTickets == this->_ticketsSize) {
		cout << "Error: all tickets was issued for play " << this->_id << " (" << this->_title << ")!" << endl;
		return nullptr;
	}

	this->_issuedTickets++;
	return this->_tickets[this->_issuedTickets - 1];
}

void Play::print(string prefix) {
	cout << prefix << "Play " << this->_id << ": " << this->_title
		<< " | Date: " << this->_date
		<< " | Roles amount: " << this->_rolesSize
		<< " | Tickets left: " << this->_ticketsSize - this->_issuedTickets
		<< " | Hall: " << endl;
	this->_hall->print(prefix + "\t");
}

void Play::printRoles(string prefix) {
	cout << prefix << "Play " << this->_id << " - " << this->_title << " - roles list: "; 
	if (this->_rolesSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_rolesSize; ++i) {
		this->_roles[i]->print(prefix + "\t" + to_string(i) + ". ");
	}
}
