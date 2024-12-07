#include <iostream>
#include "./Shop.h"

using namespace std;

// конструктор
Shop::Shop(string title, Inspector* lastInspector) : _title(title), _lastInspector(lastInspector) {
	this->_products = new Product*[0];
	this->_productsSize = 0;

	this->_employees = new Employee*[0];
	this->_employeesSize = 0;

	this->_clients = new Client*[0];
	this->_clientsSize = 0;
}

// деструктор
Shop::~Shop() {
	for(int i = 0; i < this->_productsSize; ++i) {
		delete this->_products[i];
	}
	delete[] this->_products;

	for(int i = 0; i < this->_employeesSize; ++i) {
		delete this->_employees[i];
	}
	delete[] this->_employees;

	for(int i = 0; i < this->_clientsSize; ++i) {
		delete this->_clients[i];
	}
	delete[] this->_clients;

	// cout << "___ ~Destr Shop " << this->_title << " ___" << endl;
}

// сеттеры

void Shop::setLastInspector(Inspector* lastInspector) {
	this->_lastInspector = lastInspector;
}

// геттеры

string Shop::getTitle() {
	return this->_title;
}
Inspector* Shop::getLastInspector() {
	return this->_lastInspector;
}


Employee** Shop::getEmployees() {
	return this->_employees;
}
int Shop::getEmployeesSize() {
	return this->_employeesSize;
}
Client** Shop::getClients() {
	return this->_clients;
}
int Shop::getClientsSize() {
	return this->_clientsSize;
}

// методы

void Shop::addProduct(Product* product) {
	// копируем всех работников объекта во временный массив temp
	Product** temp = new Product*[this->_productsSize];
	for(int i = 0; i < this->_productsSize; ++i) {
		temp[i] = this->_products[i];
	}
	delete[] this->_products;

	// копируем всех работников из временного массива temp обратно в массив объекта
	this->_products = new Product*[this->_productsSize+1];
	for(int i = 0; i < this->_productsSize; ++i) {
		this->_products[i] = temp[i];
	}
	// добавляем нового работника в конец массива объекта
	this->_products[this->_productsSize] = product;

	this->_productsSize++;
	delete[] temp;
}
void Shop::deleteProduct(int productIdx) {
	if (productIdx >= this->_productsSize || productIdx < 0) {
		cout << "Error: invalid productIdx was given!" << endl;
		return;
	}
	// копируем всех работников объекта во временный массив temp
	Product** temp = new Product*[this->_productsSize];
	for(int i = 0; i < this->_productsSize; ++i) {
		temp[i] = this->_products[i];
	}
	delete[] this->_products;

	// копируем всех работников из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
	this->_products = new Product*[this->_productsSize-1];
	for(int i = 0; i < productIdx; ++i) {
		this->_products[i] = temp[i];
	}
	for(int i = productIdx+1; i < this->_productsSize; ++i) {
		this->_products[i-1] = temp[i];
	}

	this->_productsSize--;
	delete[] temp;
}

void Shop::addEmployee(Employee* employee) {
	// копируем всех работников объекта во временный массив temp
	Employee** temp = new Employee*[this->_employeesSize];
	for(int i = 0; i < this->_employeesSize; ++i) {
		temp[i] = this->_employees[i];
	}
	delete[] this->_employees;

	// копируем всех работников из временного массива temp обратно в массив объекта
	this->_employees = new Employee*[this->_employeesSize+1];
	for(int i = 0; i < this->_employeesSize; ++i) {
		this->_employees[i] = temp[i];
	}
	// добавляем нового работника в конец массива объекта
	this->_employees[this->_employeesSize] = employee;

	this->_employeesSize++;
	delete[] temp;
}
void Shop::deleteEmployee(int employeeIdx) {
	if (employeeIdx >= this->_employeesSize || employeeIdx < 0) {
		cout << "Error: invalid employeeIdx was given!" << endl;
		return;
	}
	// копируем всех работников объекта во временный массив temp
	Employee** temp = new Employee*[this->_employeesSize];
	for(int i = 0; i < this->_employeesSize; ++i) {
		temp[i] = this->_employees[i];
	}
	delete[] this->_employees;

	// копируем всех работников из временного массива temp обратно в массив объекта, кроме объекта с индексом, переданным в функцию 
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

void Shop::addClient(Client* client) {
	// копируем всех клиентов объекта во временный массив temp
	Client** temp = new Client*[this->_clientsSize];
	for(int i = 0; i < this->_clientsSize; ++i) {
		temp[i] = this->_clients[i];
	}
	delete[] this->_clients;

	// копируем всех клиентов из временного массива temp обратно в массив объекта
	this->_clients = new Client*[this->_clientsSize+1];
	for(int i = 0; i < this->_clientsSize; ++i) {
		this->_clients[i] = temp[i];
	}
	// добавляем нового клиента в конец массива объекта
	this->_clients[this->_clientsSize] = client;

	this->_clientsSize++;
	delete[] temp;
}


void Shop::print(string prefix) {
	cout << prefix << "Shop " << this->_title << endl;
	
	cout << prefix + "\t" << "Last inspector:" << endl;
	this->_lastInspector->print(prefix + "\t\t");

	cout << prefix + "\t" << "Products: ";
	// печать товаров
	if (this->_productsSize == 0) {
		cout << "no one" << endl;
	} else {
		cout << endl;
		for(int i = 0; i < this->_productsSize; ++i) {
			this->_products[i]->print(prefix + "\t\t" + to_string(i) + ". ");
		}
	}

	cout << prefix + "\t" << "Employees: ";
	// печать работников
	if (this->_employeesSize == 0) {
		cout << "no one" << endl;
	} else {
		cout << endl;
		for(int i = 0; i < this->_employeesSize; ++i) {
			this->_employees[i]->print(prefix + "\t\t" + to_string(i) + ". ");
		}
	}

	// печать клиентов
	cout << prefix + "\t" << "Clients: ";
	if (this->_clientsSize == 0) {
		cout << "no one" << endl;
		return;
	}
	cout << endl;
	for(int i = 0; i < this->_clientsSize; ++i) {
		this->_clients[i]->print(prefix + "\t\t" + to_string(i) + ". ");
	}
}
