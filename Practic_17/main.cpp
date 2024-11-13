#include <iostream>

#include "./human/Human.h"
#include "./human/enums.h"
#include "./human/Child.h"
#include "./human/Adult.h"

#include "./car/Car.h"
#include "./car/enums.h"
#include "./car/PassangerCar.h"
#include "./car/Truck.h"

#include "./animal/Animal.h"
#include "./animal/enums.h"
#include "./animal/Pet.h"
#include "./animal/Wild.h"

using namespace std;


int main() {
	// -----
	// human
	// -----
	cout << endl;

	Human human("Chester", "Bennington", human::age::chester, 70, 1.8);
	cout << human;
	
	Child child("Jim", "Hawkins", 14, 50, 1.65, "School №33");
	child.displayChild();

	Adult* adult = new Adult("Ivan", "Verov", 41, 80, 1.85, "PAO \"Rostelecom\"");
	adult->displayAdult();
	delete adult;

	// ----
	// car
	// ----
	cout << endl;

	Car* car = new Car("Lada", "blue", "sedan", 1.5, 34654);
	cout << *car;
	delete car;

	PassangerCar passangerCar("Lada", "green", "sedan", 1.5, 34654, true);
	passangerCar.displayPassangerCar();

	Truck truckCar("KamAZ", "gray", "-", 2.4, 79487, false);
	truckCar.displayTruck();

	// -------
	// animal
	// -------
	cout << endl;

	Animal* animal = new Animal("Peach", "cat", "sand");
	cout << *animal;
	delete animal;
	
	Pet* pet = new Pet("Peach", "cat", "sand");
	pet->setOwner("Ivan");
	pet->displayPet();
	delete pet;

	Wild wild("Buf", "elephant", "darkgray", 5, 1500, "savannah");
	wild.displayWild();

	return 0;
}
