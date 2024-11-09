#include <iostream>
#include "Human.h"
#include "enums.h"

using namespace std;


int main() {
	// ------
	// human1
	// ------
	cout << endl;

	Human* human1 = new Human("Bob", "Marley", 35, 71.4, 1.85);

	cout << *human1;
	cout << "BodyWeightIndex: " << human1->bodyWeightIndex() << endl;
	cout << "BornYear: " << human1->bornYear() << endl;

	// ------
	// human2
	// ------
	cout << endl;
	
	{
		Human human2("Kurt", "Cobain", 27, 65);
		cout << human2;
		cout << "BodyWeightIndex: " << human2.bodyWeightIndex() << endl;
		cout << "BornYear: " << human2.bornYear() << endl;
	}

	// ------
	// human3
	// ------
	cout << endl;
	
	Human human3("Chester", "Bennington", 41);
	cout << human3;
	cout << "BodyWeightIndex: " << human3.bodyWeightIndex() << endl;
	cout << "BornYear: " << human3.bornYear() << endl;

	// ------
	// human4
	// ------
	cout << endl;

	{
		Human* human4 = new Human("Daniil", "Dudkov");
		cout << *human1;
		cout << "BodyWeightIndex: " << human4->bodyWeightIndex() << endl;
		cout << "BornYear: " << human4->bornYear() << endl;

		// ------
		// human5
		// ------
		cout << endl;

		Human human5("Freddy");
		cout << human5;
		cout << "BodyWeightIndex: " << human5.bodyWeightIndex() << endl;
		cout << "BornYear: " << human5.bornYear() << endl;

		delete human4;
	}

	delete human1;

	// ------
	// human6
	// ------
	cout << endl;

	Human* human6 = new Human();
	cout << *human6;
	human6->setFirstName("Cara");
	human6->setLastName("Delevingne");
	
	human6->setAge(-24);
	cout << *human6;
	human6->setAge(24);
	
	human6->setWeight(53);
	human6->setHeight(0.1);
	cout << *human6;
	human6->setHeight(1.65);
	
	cout << *human6 << endl;
	cout << "BodyWeightIndex: " << human6->bodyWeightIndex() << endl;
	cout << "BornYear: " << human6->bornYear() << endl;


	// перегрузы
	cout << endl << "*** перегрузы ***" << endl << endl;

	human3.setHeight(1.8);
	cout << human3;

	if (*human6 > human3) {
		cout << "human6 is higher than human3" << endl;
	} else if (*human6 < human3) {
		cout << "human3 is higher than human6" << endl;
	} else {
		cout << "human3 height is equal to human6 height" << endl;
	}

	++(*human6);
	++(*human6);
	cout << endl << *human6;

	if (*human6 > human3) {
		cout << "human6 is higher than human3" << endl;
	} else if (*human6 < human3) {
		cout << "human3 is higher than human6" << endl;
	} else {
		cout << "human3 height is equal to human6 height" << endl;
	}

	delete human6;

	// enum и namespace
	cout << endl << "*** enum и namespace ***" << endl << endl;

	Human* kurt = new Human("Kurt", "Cobain", human::age::kurt);
	Human* jimi = new Human("Jimi", "Hendrix", human::age::jimi);
	Human* chester = new Human("Chester", "Benington", human::age::chester);

	cout << endl << *kurt << *jimi << *chester << endl;

	return 0;
}
