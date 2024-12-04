#include <iostream>
#include "./Critic.h"
#include "../Play/Ticket.h"

using namespace std;


// конструкторы
Critic::Critic(string firstName, string lastName, int age, int experience) :
	IPerson(firstName, lastName), Client(firstName, lastName), IEmployee(firstName, lastName, age, experience) {}
Critic::Critic() : Critic("-", "-", 0, 0) {}

// деструктор
Critic::~Critic() {
	// cout << "___ ~Destr Critic " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// методы

void Critic::print(string prefix) {
	cout << prefix << "Critic: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->getAge()
		<< " | Experience: " << this->getExperience()
		<< " | Tickets: ";

	int* ticketsSize = new int;
	*ticketsSize = this->getTicketsSize();

	if (*ticketsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;

	Ticket** temp = this->getTickets();
	for(int i = 0; i < *ticketsSize; ++i) {
		temp[i]->print(prefix + "\t" + to_string(i) + ". ");
	}

	delete ticketsSize;
}
