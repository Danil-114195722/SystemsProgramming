#include <iostream>

#include "./Library/Library.h"

#include "./Persons/IPerson.h"
#include "./Persons/Employee.h"
#include "./Persons/Visitors/IVisitor.h"
#include "./Persons/Visitors/Guest.h"
#include "./Persons/Visitors/Client.h"

#include "./Literature/ILiterature.h"
#include "./Literature/Book.h"
#include "./Literature/Newspaper.h"
#include "./Literature/Magazine.h"


void addLiteratureForVisitors(Library* library) {
	cout << "\nGive book 1984 to guest Maxim Petrov\n";
	library->giveLiteratureToGuest(0, 2);
	cout << "\nGive book Woe From Mind to client Nikita Nikitin\n";
	library->giveLiteratureToClient(1, 0);
	cout << "\nGive magazine Burda 1/2004 to client Maxim Pravy\n";
	library->giveLiteratureToClient(4, 1);
	cout << "\nGive newspaper to guest Ivan Kruglov\n";
	library->giveLiteratureToGuest(2, 0);
	cout << "\nGive book Evgeny Onegin to guest Ivan Kruglov\n";
	library->giveLiteratureToGuest(1, 0);
	cout << "\n";
}

void returnLiteratureFromVisitors(Library* library) {
	cout << "\nReturn book 1984 from guest Maxim Petrov\n";
	library->returnLiteratureFromGuest(0, 2);
	cout << "\nReturn magazine Burda 1/2004 from client Maxim Pravy\n";
	library->returnLiteratureFromClient(0, 1);
	cout << "\n";
}

int main() {
	// создание книг
	ILiterature* book1 = new Book(1949, "England", "George Orwell", "1984", "dystopian");
	ILiterature* book2 = new Book(1838, "St.Peterburg", "Alexander Griboedov", "Woe From Mind", "comedy");
	ILiterature* book3 = new Book(1828, "St.Peterburg", "Alexander Pushkin", "Evgeny Onegin", "novel");

	// создание газет
	int newspaper1ThemesSize = 3;
	string* newspaper1Themes = new string[newspaper1ThemesSize]{
		"How to remove rectum?",
		"Why you cannot sell one kidney and keep the second?",
		"Great conspiracy"
	};
	ILiterature* newspaper1 = new Newspaper(2017, "St.Peterburg", newspaper1Themes, newspaper1ThemesSize);

	// создание журналов
	int magazine1ThemesSize = 2;
	string* magazine1Themes = new string[magazine1ThemesSize]{
		"Судоку",
		"Это интересно"
	};
	ILiterature* magazine1 = new Magazine(2007, "ЗАО Редакция журнала Мурзилка", "РГДБ", "Мурзилка. 2007. № 01", magazine1Themes, magazine1ThemesSize);

	int magazine2ThemesSize = 3;
	string* magazine2Themes = new string[magazine2ThemesSize]{
		"Классика",
		"Мода Plus",
		"Актуальный дизайн"
	};
	ILiterature* magazine2 = new Magazine(2004, "ИД «Бурда»", "Энне Бурда", "Burda 1/2004", magazine2Themes, magazine2ThemesSize);

	// создание работников
	Employee* employee1 = new Employee("Ivan", "Kostolomov", 32, "security");
	Employee* employee2 = new Employee("Gleb", "Gromov", 37, "security");
	Employee* employee3 = new Employee("Galina", "Ponchik", 27, "librarian");
	Employee* employee4 = new Employee("Darina", "Serova", 24, "admin");

	// создание гостей
	Guest* guest1 = new Guest("Ivan", "Kruglov", 28, "+7(909)256-35-80", false);
	Guest* guest2 = new Guest("Andrey", "Sidorov", 37, "+7(998)376-38-75", false);
	Guest* guest3 = new Guest("Maxim", "Petrov", 65, "+7(900)538-65-03", false);

	// создание клиентов
	Client* client1 = new Client("Nikita", "Nikitin", 55, "+7(905)667-56-94", true, "67493");
	Client* client2 = new Client("Maxim", "Pravy", 37, "+7(961)385-23-96", false, "67620");
	Client* client3 = new Client("Dmitry", "Sedov", 43, "+7(901)346-86-29", true, "76930");
	
	Library* publicLibrary = new Library("Public Library");
	publicLibrary->print();
	// добавление литературы
	publicLibrary->addLiterature(book1);
	publicLibrary->addLiterature(book2);
	publicLibrary->addLiterature(book3);
	publicLibrary->addLiterature(newspaper1);
	publicLibrary->addLiterature(magazine1);
	publicLibrary->addLiterature(magazine2);
	// добавление работников
	publicLibrary->addEmployee(employee1);
	publicLibrary->addEmployee(employee2);
	publicLibrary->addEmployee(employee3);
	publicLibrary->addEmployee(employee4);
	// добавление гостей
	publicLibrary->addGuest(guest1);
	publicLibrary->addGuest(guest2);
	publicLibrary->addGuest(guest3);
	// добавление клиентов
	publicLibrary->addClient(client1);
	publicLibrary->addClient(client2);
	publicLibrary->addClient(client3);

	publicLibrary->print();
	// печать всей литературы библиотеки
	publicLibrary->printLiterature();
	// печать всех работников библиотеки
	publicLibrary->printEmployees();
	// печать всех гостей библиотеки
	publicLibrary->printGuests();
	// печать всех клиентов библиотеки
	publicLibrary->printClients();

	addLiteratureForVisitors(publicLibrary);

	publicLibrary->print();
	// печать всей литературы библиотеки
	publicLibrary->printLiterature();
	// печать всех гостей библиотеки
	publicLibrary->printGuests();
	// печать всех клиентов библиотеки
	publicLibrary->printClients();

	returnLiteratureFromVisitors(publicLibrary);

	publicLibrary->print();
	// печать всей литературы библиотеки
	publicLibrary->printLiterature();
	// печать всех гостей библиотеки
	publicLibrary->printGuests();
	// печать всех клиентов библиотеки
	publicLibrary->printClients();

	cout << "\nRemove employee Ivan Kostolomov\n" << endl;
	publicLibrary->deleteEmployee(0);

	publicLibrary->print();
	// печать всех работников библиотеки
	publicLibrary->printEmployees();

	cout << "\nRemove guest Maxim Petrov\n" << endl;
	publicLibrary->deleteGuest(2);

	publicLibrary->print();
	// печать всех работников библиотеки
	publicLibrary->printGuests();

	delete book1;
	delete book2;
	delete book3;
	delete newspaper1;
	delete magazine1;
	delete magazine2;

	delete employee1;
	delete employee2;
	delete employee3;
	delete employee4;

	delete guest1;
	delete guest2;
	delete guest3;

	delete client1;
	delete client2;
	delete client3;

	delete publicLibrary;

	return 0;
}
