#include <iostream>

#include "./Theatre/Theatre.h"
#include "./Theatre/Hall.h"

#include "./Persons/IPerson.h"
#include "./Persons/Client.h"
#include "./Persons/Actor.h"
#include "./Persons/Critic.h"

#include "./Play/Ticket.h"
#include "./Play/Role.h"
#include "./Play/Play.h"


void initTheatre(Theatre* theatre) {
	// актёры

	Actor* actor1 = new Actor("Illona", "Ogir", 38, 15, "F", "St.Peterburg University");
	Actor* actor2 = new Actor("Alexey", "Timchenko", 37, 15, "M", "Saratov State Concervatory");
	Actor* actor3 = new Actor("Evgeny", "Onegin", 27, 190, "M", "Pushkin book");
	Actor* actor4 = new Actor("Ann", "Vasilyeva", 50, 25, "F", "All-Russian State Cinema University");
	Actor* actor5 = new Actor("Elizaveta", "Popova", 29, 8, "F", "Moscow State University");
	Actor* actor6 = new Actor("Darina", "Serova", 24, 5, "F", "All-Russian State Cinema University");

	theatre->addActor(actor1);
	theatre->addActor(actor2);
	theatre->addActor(actor3);
	theatre->addActor(actor4);
	theatre->addActor(actor5);
	theatre->addActor(actor6);

	// залы

	Hall* hall1 = new Hall(304, 4);
	Hall* hall2 = new Hall(102, 7);
	Hall* hall3 = new Hall(208, 11);

	theatre->addHall(hall1);
	theatre->addHall(hall2);
	theatre->addHall(hall3);

	// первый спектакль

	int* playRolesAmount = new int;	

	Role* role11 = new Role("Snow-white", "Snow-white", 18, actor1);
	Role* role12 = new Role("Dwarf 1", "Dwarf", 14, actor2);
	Role* role13 = new Role("Dwarf 2", "Dwarf", 14, actor3);

	*playRolesAmount = 3;
	Role** playRoles = new Role*[*playRolesAmount]{role11, role12, role13};
	
	Play* play1 = new Play("Snow-white and two dwarfs", "20-12-2024", hall1, playRoles, *playRolesAmount);
	delete playRoles;
	theatre->addPlay(play1);

	// второй спектакль

	Role* role21 = new Role("Cinderella", "Cinderella", 18, actor1);
	Role* role22 = new Role("Kind fairy", "Fairy", 45, actor4);
	Role* role23 = new Role("Prince", "Prince Mirlifloor", 22, actor2);

	*playRolesAmount = 3;
	playRoles = new Role*[*playRolesAmount]{role21, role22, role23};
	
	Play* play2 = new Play("Cinderella", "24-12-2024", hall2, playRoles, *playRolesAmount);
	delete playRoles;
	theatre->addPlay(play2);

	// третий спектакль

	Role* role31 = new Role("Grandpa", "Grandpa", 70, actor3);
	Role* role32 = new Role("Grandma", "Grandma", 65, actor4);
	Role* role33 = new Role("Granddaughter", "Granddaughter", 13, actor6);
	Role* role34 = new Role("Dog", "Zhuchka", 5, actor2);
	Role* role35 = new Role("Cat", "Cat", 7, actor1);
	Role* role36 = new Role("Mouse", "Mouse", 1, actor5);

	*playRolesAmount = 6;
	playRoles = new Role*[*playRolesAmount]{role31, role32, role33, role34, role35, role36};
	
	Play* play3 = new Play("Turnip", "02-01-2025", hall3, playRoles, *playRolesAmount);
	delete playRoles;
	theatre->addPlay(play3);

	delete playRolesAmount;
}

int main() {
	Theatre* theatre = new Theatre("ТЮЗ");
	initTheatre(theatre);

	// посетители
	Client* client1 = new Client("Nikita", "Nikitin");
	Client* client2 = new Client("Maxim", "Pravy");
	Client* client3 = new Client("Dmitry", "Sedov");

	// критики
	Critic* critic1 = new Critic("Galina", "Ponchik", 27, 5);
	Critic* critic2 = new Critic("Andrey", "Chervyak-Voronich", 35, 10);
	Critic* critic3 = new Critic("Dmitry", "Berdnik-Berdichenko", 43, 17);

	theatre->print();
	theatre->printHalls();
	theatre->printPlays();
	theatre->printActors();

	cout << endl << "client1 buy ticket for play 1" << endl;
	theatre->buyTicket(client1, 0);
	client1->print();

	cout << endl << "client2 buy ticket for play 1" << endl;
	theatre->buyTicket(client2, 0);
	client2->print();

	cout << endl << "client3 buy ticket for play 2" << endl;
	theatre->buyTicket(client3, 1);
	client3->print();

	cout << endl << "critic1 buy tickets for plays 1 and 2 " << endl;
	theatre->buyTicket(critic1, 0);
	theatre->buyTicket(critic1, 1);
	critic1->print();

	cout << endl << "critic2 buy tickets for all plays" << endl;
	theatre->buyTicket(critic2, 0);
	theatre->buyTicket(critic2, 1);
	theatre->buyTicket(critic2, 2);
	critic2->print();

	cout << endl << "critic3 buy tickets for all plays" << endl;
	theatre->buyTicket(critic3, 0);
	theatre->buyTicket(critic3, 2);
	theatre->buyTicket(critic3, 1);
	critic3->print();

	cout << endl;
	theatre->printPlays();

	delete client1;
	delete client2;
	delete client3;

	delete critic1;
	delete critic2;
	delete critic3;

	delete theatre;

	return 0;
}
