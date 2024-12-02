#include <iostream>
#include "Library.h"

using namespace std;


// конструкторы
Library::Library(string title) : _title(title) {
	this->_literature = new ILiterature*[0];
	this->_literatureSize = 0;

	this->_employees = new Employee*[0];
	this->_employeesSize = 0;

	this->_guests = new Guest*[0];
	this->_guestsSize = 0;

	this->_clients = new Client*[0];
	this->_clientsSize = 0;	
}
Library::Library() : Library("-") {}

// деструктор
Library::~Library() {
	delete[] this->_literature;
	delete[] this->_employees;
	delete[] this->_guests;
	delete[] this->_clients;
}

// сеттеры

void Library::setTitle(string title) {
	this->_title = title;
}

// геттеры

string Library::getTitle() {
	return this->_title;
}

ILiterature** Library::getLiterature() {
	return this->_literature;
}
int Library::getLiteratureSize() {
	return this->_literatureSize;
}

Employee** Library::getEmployees() {
	return this->_employees;
}
int Library::getEmployeesSize() {
	return this->_employeesSize;
}

Guest** Library::getGuests() {
	return this->_guests;
}
int Library::getGuestsSize() {
	return this->_guestsSize;
}

Client** Library::getClients() {
	return this->_clients;
}
int Library::getClientsSize() {
	return this->_clientsSize;
}

// методы

void Library::addLiterature(ILiterature* literature) {
	// копируем всю литературу объекта во временный массив temp
	ILiterature** temp = new ILiterature*[this->_literatureSize];
	for(int i = 0; i < this->_literatureSize; ++i) {
		temp[i] = this->_literature[i];
	}
	delete[] this->_literature;

	// копируем всю литературу из временного массива temp обратно в массив объекта
	this->_literature = new ILiterature*[this->_literatureSize+1];
	for(int i = 0; i < this->_literatureSize; ++i) {
		this->_literature[i] = temp[i];
	}
	// добавляем новую литературу в конец массива объекта
	this->_literature[this->_literatureSize] = literature;

	this->_literatureSize++;
	delete[] temp;
}
void Library::deleteLiterature(int literatureIdx) {
	if (literatureIdx >= this->_literatureSize || literatureIdx < 0) {
		cout << "Error: invalid literatureIdx was given!" << endl;
		return;
	}
	// копируем всю литературу объекта во временный массив temp
	ILiterature** temp = new ILiterature*[this->_literatureSize];
	for(int i = 0; i < this->_literatureSize; ++i) {
		temp[i] = this->_literature[i];
	}
	delete[] this->_literature;

	// копируем всю литературу из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_literature = new ILiterature*[this->_literatureSize-1];
	for(int i = 0; i < literatureIdx; ++i) {
		this->_literature[i] = temp[i];
	}
	for(int i = literatureIdx+1; i < this->_literatureSize; ++i) {
		this->_literature[i-1] = temp[i];
	}

	this->_literatureSize--;
	delete[] temp;
}

void Library::addEmployee(Employee* employee) {
	// копируем всю литературу объекта во временный массив temp
	Employee** temp = new Employee*[this->_employeesSize];
	for(int i = 0; i < this->_employeesSize; ++i) {
		temp[i] = this->_employees[i];
	}
	delete[] this->_employees;

	// копируем всю литературу из временного массива temp обратно в массив объекта
	this->_employees = new Employee*[this->_employeesSize+1];
	for(int i = 0; i < this->_employeesSize; ++i) {
		this->_employees[i] = temp[i];
	}
	// добавляем новую литературу в конец массива объекта
	this->_employees[this->_employeesSize] = employee;

	this->_employeesSize++;
	delete[] temp;
}
void Library::deleteEmployee(int employeeIdx) {
	if (employeeIdx >= this->_employeesSize || employeeIdx < 0) {
		cout << "Error: invalid employeeIdx was given!" << endl;
		return;
	}
	// копируем всю литературу объекта во временный массив temp
	Employee** temp = new Employee*[this->_employeesSize];
	for(int i = 0; i < this->_employeesSize; ++i) {
		temp[i] = this->_employees[i];
	}
	delete[] this->_employees;

	// копируем всю литературу из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_employees = new Employee*[this->_employeesSize-1];
	for(int i = 0; i < employeeIdx; ++i) {
		this->_employees[i] = temp[i];
	}
	for(int i = employeeIdx+1; i < this->_employeesSize; ++i) {
		this->_employees[i-1] = temp[i];
	}

	this->_employeesSize--;
	delete[] temp;
}

void Library::Library::addGuest(Guest* guest) {
	// копируем всю литературу объекта во временный массив temp
	Guest** temp = new Guest*[this->_guestsSize];
	for(int i = 0; i < this->_guestsSize; ++i) {
		temp[i] = this->_guests[i];
	}
	delete[] this->_guests;

	// копируем всю литературу из временного массива temp обратно в массив объекта
	this->_guests = new Guest*[this->_guestsSize+1];
	for(int i = 0; i < this->_guestsSize; ++i) {
		this->_guests[i] = temp[i];
	}
	// добавляем новую литературу в конец массива объекта
	this->_guests[this->_guestsSize] = guest;

	this->_guestsSize++;
	delete[] temp;
}
void Library::deleteGuest(int guestIdx) {
	if (guestIdx >= this->_guestsSize || guestIdx < 0) {
		cout << "Error: invalid guestIdx was given!" << endl;
		return;
	}
	// копируем всю литературу объекта во временный массив temp
	Guest** temp = new Guest*[this->_guestsSize];
	for(int i = 0; i < this->_guestsSize; ++i) {
		temp[i] = this->_guests[i];
	}
	delete[] this->_guests;

	// копируем всю литературу из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_guests = new Guest*[this->_guestsSize-1];
	for(int i = 0; i < guestIdx; ++i) {
		this->_guests[i] = temp[i];
	}
	for(int i = guestIdx+1; i < this->_guestsSize; ++i) {
		this->_guests[i-1] = temp[i];
	}

	this->_guestsSize--;
	delete[] temp;
}

void Library::addClient(Client* client) {
	// копируем всю литературу объекта во временный массив temp
	Client** temp = new Client*[this->_clientsSize];
	for(int i = 0; i < this->_clientsSize; ++i) {
		temp[i] = this->_clients[i];
	}
	delete[] this->_clients;

	// копируем всю литературу из временного массива temp обратно в массив объекта
	this->_clients = new Client*[this->_clientsSize+1];
	for(int i = 0; i < this->_clientsSize; ++i) {
		this->_clients[i] = temp[i];
	}
	// добавляем новую литературу в конец массива объекта
	this->_clients[this->_clientsSize] = client;

	this->_clientsSize++;
	delete[] temp;
}
void Library::deleteClient(int clientIdx) {
	if (clientIdx >= this->_clientsSize || clientIdx < 0) {
		cout << "Error: invalid clientIdx was given!" << endl;
		return;
	}
	// копируем всю литературу объекта во временный массив temp
	Client** temp = new Client*[this->_clientsSize];
	for(int i = 0; i < this->_clientsSize; ++i) {
		temp[i] = this->_clients[i];
	}
	delete[] this->_clients;

	// копируем всю литературу из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_clients = new Client*[this->_clientsSize-1];
	for(int i = 0; i < clientIdx; ++i) {
		this->_clients[i] = temp[i];
	}
	for(int i = clientIdx+1; i < this->_clientsSize; ++i) {
		this->_clients[i-1] = temp[i];
	}

	this->_clientsSize--;
	delete[] temp;
}

void Library::print() {
	cout << "Library: " << this->_title
		<< " | Literature: " << this->_literatureSize
		<< " | Employees: " << this->_employeesSize
		<< " | Guests: " << boolalpha << this->_guestsSize
		<< " | Clients: " << boolalpha << this->_clientsSize << endl;
}

void Library::printLiterature() {
	cout << this->_title << " literature:";
	if (this->_literatureSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;

	for(int i = 0; i < this->_literatureSize; ++i) {
		cout << "\t" << i << ". ";
		this->_literature[i]->print("\t");
	}
}

void Library::printEmployees() {
	cout << this->_title << " employees:";
	if (this->_employeesSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;

	for(int i = 0; i < this->_employeesSize; ++i) {
		cout << "\t" << i << ". ";
		this->_employees[i]->print("\t");
	}
}

void Library::printGuests() {
	cout << this->_title << " guests:";
	if (this->_guestsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;

	for(int i = 0; i < this->_guestsSize; ++i) {
		cout << "\t" << i << ". ";
		this->_guests[i]->print("\t");
	}
}

void Library::printClients() {
	cout << this->_title << " clients:";
	if (this->_clientsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;

	for(int i = 0; i < this->_clientsSize; ++i) {
		cout << "\t" << i << ". ";
		this->_clients[i]->print("\t");
	}
}

void Library::giveLiteratureToGuest(int libraryLiteratureIdx, int guestIdx) {
	if (libraryLiteratureIdx >= this->_literatureSize || libraryLiteratureIdx < 0) {
		cout << "Error: invalid libraryLiteratureIdx was given!" << endl;
		return;
	}
	if (guestIdx >= this->_guestsSize || guestIdx < 0) {
		cout << "Error: invalid guestIdx was given!" << endl;
		return;
	}
	this->_guests[guestIdx]->addLiteratureToRead(this->_literature[libraryLiteratureIdx]);
}
void Library::returnLiteratureFromGuest(int guestLiteratureIdx, int guestIdx) {
	if (guestLiteratureIdx >= this->_guests[guestIdx]->getLiteratureToReadSize() || guestLiteratureIdx < 0) {
		cout << "Error: invalid guestLiteratureIdx was given!" << endl;
		return;
	}
	if (guestIdx >= this->_guestsSize || guestIdx < 0) {
		cout << "Error: invalid guestIdx was given!" << endl;
		return;
	}
	this->_guests[guestIdx]->deleteLiteratureToRead(guestLiteratureIdx);
}

void Library::giveLiteratureToClient(int libraryLiteratureIdx, int clientIdx) {
	if (libraryLiteratureIdx >= this->_literatureSize || libraryLiteratureIdx < 0) {
		cout << "Error: invalid libraryLiteratureIdx was given!" << endl;
		return;
	}
	if (clientIdx >= this->_clientsSize || clientIdx < 0) {
		cout << "Error: invalid clientIdx was given!" << endl;
		return;
	}
	this->_clients[clientIdx]->addTakenLiterature(this->_literature[libraryLiteratureIdx]);
	this->deleteLiterature(libraryLiteratureIdx);
}
void Library::returnLiteratureFromClient(int clientLiteratureIdx, int clientIdx) {
	if (clientLiteratureIdx >= this->_clients[clientIdx]->getTakenLiteratureSize() || clientLiteratureIdx < 0) {
		cout << "Error: invalid clientLiteratureIdx was given!" << endl;
		return;
	}
	if (clientIdx >= this->_clientsSize || clientIdx < 0) {
		cout << "Error: invalid clientIdx was given!" << endl;
		return;
	}
	this->addLiterature(this->_clients[clientIdx]->getTakenLiterature()[clientLiteratureIdx]);
	this->_clients[clientIdx]->deleteTakenLiterature(clientLiteratureIdx);
}
