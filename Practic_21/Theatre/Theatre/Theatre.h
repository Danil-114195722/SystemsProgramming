#pragma once
#include <iostream>
#include "./Hall.h"
#include "../Play/Play.h"
#include "../Persons/Actor.h"

#include "../Play/Ticket.h"
#include "../Persons/Client.h"
// #include "../Persons/Critic.h"

using namespace std;


class Theatre {
	public:
		// конструктор
		Theatre(string title);

		// деструкторы
		~Theatre();

		// геттеры
		string getTitle();
		Hall** getHalls();
		int getHallsSize();
		Play** getPlays();
		int getPlaysSize();
		Actor** getActors();
		int getActorsSize();

		// сеттеры
		void setTitle(string title);

		// методы
		void addHall(Hall* hall);
		void deleteHall(int hallIdx);

		void addPlay(Play* play);
		void deletePlay(int playIdx);

		void addActor(Actor* actor);
		void deleteActor(int actorIdx);

		void print(string prefix = "");
		void printHalls(string prefix = "");
		void printPlays(string prefix = "");
		void printActors(string prefix = "");

		void buyTicket(Client* client, int playIdx);

	private:
		// поля
		string _title;
		
		Hall** _halls;
		int _hallsSize;

		Play** _plays;
		int _playsSize;

		Actor** _actors;
		int _actorsSize;
};
