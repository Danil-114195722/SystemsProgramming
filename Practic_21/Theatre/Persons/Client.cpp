#include <iostream>
#include "./Client.h"
#include "../Play/Ticket.h"

using namespace std;


// конструкторы
Client::Client(string firstName, string lastName) : IPerson(firstName, lastName) {
	this->_tickets = new Ticket*[0];
	this->_ticketsSize = 0;
}
Client::Client() : Client("-", "-") {}

// деструктор
Client::~Client() {
	delete[] this->_tickets;
	// cout << "___ ~Destr Client " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// геттеры

Ticket** Client::getTickets() {
	return this->_tickets;
}

int Client::getTicketsSize() {
	return this->_ticketsSize;
}

// методы

void Client::addTicket(Ticket* ticket) {
	// копируем все билеты объекта во временный массив temp
	Ticket** temp = new Ticket*[this->_ticketsSize];
	for(int i = 0; i < this->_ticketsSize; ++i) {
		temp[i] = this->_tickets[i];
	}
	delete[] this->_tickets;

	// копируем все билеты из временного массива temp обратно в массив объекта
	this->_tickets = new Ticket*[this->_ticketsSize+1];
	for(int i = 0; i < this->_ticketsSize; ++i) {
		this->_tickets[i] = temp[i];
	}
	// добавляем новый билет в конец массива объекта
	this->_tickets[this->_ticketsSize] = ticket;

	this->_ticketsSize++;
	delete[] temp;
}

void Client::deleteTicket(int ticketIdx) {
	if (ticketIdx >= this->_ticketsSize || ticketIdx < 0) {
		cout << "Error: invalid ticketIdx was given!" << endl;
		return;
	}
	// копируем все билеты объекта во временный массив temp
	Ticket** temp = new Ticket*[this->_ticketsSize];
	for(int i = 0; i < this->_ticketsSize; ++i) {
		temp[i] = this->_tickets[i];
	}
	delete[] this->_tickets;

	// копируем все билеты из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_tickets = new Ticket*[this->_ticketsSize-1];
	for(int i = 0; i < ticketIdx; ++i) {
		this->_tickets[i] = temp[i];
	}
	for(int i = ticketIdx+1; i < this->_ticketsSize; ++i) {
		this->_tickets[i-1] = temp[i];
	}

	this->_ticketsSize--;
	delete[] temp;
}

void Client::print(string prefix) {
	cout << prefix << "Client: " << this->getFirstName() << " " << this->getLastName() << " | Tickets: ";

	if (this->_ticketsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	
	for(int i = 0; i < this->_ticketsSize; ++i) {
		this->_tickets[i]->print(prefix + "\t" + to_string(i) + ". ");
	}
}
