#pragma once
#include <iostream>
#include "../Persons/Employee.h"
#include "../Persons/Visitors/Guest.h"
#include "../Persons/Visitors/Client.h"
#include "../Literature/ILiterature.h"

using namespace std;


class Library {
	public:
		// конструкторы
		Library(string title);
		Library();

		// деструкторы
		~Library();

		// сеттеры
		void setTitle(string cardId);
		
		// геттеры

		string getTitle();

		ILiterature** getLiterature();
		int getLiteratureSize();
		
		Employee** getEmployees();
		int getEmployeesSize();
		
		Guest** getGuests();
		int getGuestsSize();
		
		Client** getClients();
		int getClientsSize();
		
		// методы
		void addLiterature(ILiterature* literature);
		void deleteLiterature(int literatureIdx);

		void addEmployee(Employee* employee);
		void deleteEmployee(int employeeIdx);
		
		void addGuest(Guest* guest);
		void deleteGuest(int guestIdx);
		
		void addClient(Client* client);
		void deleteClient(int clientIdx);
		
		void print();
		void printLiterature();
		void printEmployees();
		void printGuests();
		void printClients();

		void giveLiteratureToGuest(int libraryLiteratureIdx, int guestIdx);
		void returnLiteratureFromGuest(int guestLiteratureIdx, int guestIdx);

		void giveLiteratureToClient(int libraryLiteratureIdx, int clientIdx);
		void returnLiteratureFromClient(int clientLiteratureIdx, int clientIdx);

	private:
		string _title;
		
		ILiterature** _literature;
		int _literatureSize;

		Employee** _employees;
		int _employeesSize;

		Guest** _guests;
		int _guestsSize;

		Client** _clients;
		int _clientsSize;
};
