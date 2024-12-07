#pragma once
#include <iostream>
#include "./Product.h"
#include "../Persons/Client.h"
#include "../Persons/Employee.h"
#include "../Persons/Inspector.h"

using namespace std;


class Shop {
	public:
		// конструктор
		Shop(string title, Inspector* lastInspector);

		// деструкторы
		~Shop();

		// сеттеры

		void setLastInspector(Inspector* lastInspector);

		// геттеры

		string getTitle();
		Inspector* getLastInspector();

		Product** getProducts();
		int getProductsSize();
		
		Employee** getEmployees();
		int getEmployeesSize();
		
		Client** getClients();
		int getClientsSize();

		// методы
		void addProduct(Product* product);
		void deleteProduct(int productIdx);

		void addEmployee(Employee* employee);
		void deleteEmployee(int employeeIdx);

		void addClient(Client* client);

		void print(string prefix = "");

	private:
		// поля
		string _title;
		Inspector* _lastInspector;

		Product** _products;
		int _productsSize;

		Employee** _employees;
		int _employeesSize;

		Client** _clients;
		int _clientsSize;
};
