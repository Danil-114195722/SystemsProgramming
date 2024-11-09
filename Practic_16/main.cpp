#include <iostream>

#include "./human/Human.h"
#include "./human/enums.h"

#include "./car/Car.h"
#include "./car/enums.h"

#include "./animal/Animal.h"
#include "./animal/enums.h"

using namespace std;
using namespace car;


int main() {
	// ------
	// human3
	// ------
	cout << endl;

	Human human3("Chester", "Bennington", 41);
	cout << human3;
	cout << "BornYear: " << human3.bornYear() << endl;

	// ------
	// human6
	// ------
	cout << endl;

	Human* human6 = new Human();
	cout << *human6;
	human6->setFirstName("Cara");
	human6->setLastName("Delevingne");
	human6->setAge(-24);
	human6->setWeight(53);
	human6->setHeight(1.65);
	
	cout << *human6;
	cout << "BodyWeightIndex: " << human6->bodyWeightIndex() << endl;

	// enum и namespace для Human
	cout << endl << "*** enum и namespace ***" << endl;

	Human* kurt = new Human("Kurt", "Cobain", human::age::kurt);
	Human* jimi = new Human("Jimi", "Hendrix", human::age::jimi);
	Human* chester = new Human("Chester", "Benington", human::age::chester);

	cout << endl << *kurt << *jimi << *chester << endl;

	delete human6;
	delete kurt;
	delete jimi;
	delete chester;

	// ----
	// car1
	// ----

	Car* car1 = new Car();
	cout << *car1;
	car1->setBrend("Lada");
	car1->setMotorCapacity(-1.4);
	car1->setMileage(mileage::lada);
	cout << *car1 << endl;

	delete car1;

	// -------
	// animal1
	// -------

	Animal* animal1 = new Animal("Peach", "cat", "sand");
	cout << *animal1;
	animal1->setAge(animal::age::dogShepherd + 2);
	cout << *animal1;

	delete animal1;

	return 0;
}
