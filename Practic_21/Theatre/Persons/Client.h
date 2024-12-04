#pragma once
#include <iostream>
#include "./IPerson.h"
#include "../Play/Ticket.h"

using namespace std;


class Client : virtual public IPerson {
	public:
		// конструкторы
		Client(string firstName, string lastName);
		Client();

		// деструкторы
		virtual ~Client();

		// геттеры
		Ticket** getTickets();
		int getTicketsSize();

		// методы
		void addTicket(Ticket* ticket);
		void deleteTicket(int ticketIdx);

		virtual void print(string prefix = "");

	private:
		// поля
		Ticket** _tickets;
		int _ticketsSize;
};
