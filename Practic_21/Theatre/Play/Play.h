#pragma once
#include <iostream>
#include "./Role.h"
#include "./Ticket.h"
#include "../Theatre/Hall.h"

using namespace std;


class Play {
	static int counter;

	public:
		// конструктор
		Play(string title, string date, Hall* hall, Role** roles, int rolesSize);

		// деструкторы
		~Play();

		// геттеры

		int getId();
		string getTitle();
		string getDate();
		Hall* getHall();
		Role** getRoles();
		int getRolesSize();
		Ticket** getTickets();
		int getIssuedTickets();

		// сеттеры

		void setTitle(string title);
		void setDate(string date);
		void setHall(Hall* hall);
		void setRoles(Role** roles, int rolesSize);

		// методы
		Ticket* issueTicket();

		void print(string prefix = "");
		void printRoles(string prefix = "");

	private:
		// поля
		int _id;
		string _title;
		string _date;
		Hall* _hall;

		Role** _roles;
		int _rolesSize;

		Ticket** _tickets;
		int _ticketsSize;
		int _issuedTickets;
};
