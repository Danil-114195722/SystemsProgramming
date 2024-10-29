#include <iostream>
#include "Human.h"

using namespace std;


int main() {
	// ------
	// human1
	// ------
	cout << endl;

	Human* human1 = new Human("Bob", "Marley", 35, 71.4, 1.85);

	human1->print();
	cout << "BodyWeightIndex: " << human1->bodyWeightIndex() << endl;
	cout << "BornYear: " << human1->bornYear() << endl;

	// ------
	// human2
	// ------
	cout << endl;
	
	{
		Human human2("Kurt", "Cobain", 27, 65);
		human2.print();
		cout << "BodyWeightIndex: " << human2.bodyWeightIndex() << endl;
		cout << "BornYear: " << human2.bornYear() << endl;
	}

	// ------
	// human3
	// ------
	cout << endl;
	
	Human human3("Chester", "Bennington", 41);
	human3.print();
	cout << "BodyWeightIndex: " << human3.bodyWeightIndex() << endl;
	cout << "BornYear: " << human3.bornYear() << endl;

	// ------
	// human4
	// ------
	cout << endl;

	{
		Human* human4 = new Human("Daniil", "Dudkov");
		human1->print();
		cout << "BodyWeightIndex: " << human4->bodyWeightIndex() << endl;
		cout << "BornYear: " << human4->bornYear() << endl;

		// ------
		// human5
		// ------
		cout << endl;

		Human human5("Freddy");
		human5.print();
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
	human6->print();
	human6->setFirstName("Cara");
	human6->setLastName("Delevingne");
	
	human6->setAge(-24);
	human6->print();
	human6->setAge(24);
	
	human6->setWeight(53);
	human6->setHeight(0.1);
	human6->print();
	human6->setHeight(1.65);
	
	human6->print();
	cout << "BodyWeightIndex: " << human6->bodyWeightIndex() << endl;
	cout << "BornYear: " << human6->bornYear() << endl;


	delete human6;

	return 0;
}
