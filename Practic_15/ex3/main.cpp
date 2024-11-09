#include <iostream>
#include "Animal.h"
#include "enums.h"

using namespace std;
using namespace animal;


int main() {
	// -------
	// animal1
	// -------
	
	Animal animal1("Peach", "cat", "sand", 4, 6);

	int* days1 = new int;
	*days1 = 50;
	string* newName1 = new string;
	*newName1 = "Peach 2.0";

	animal1.print();
	cout << "Feed " << animal1.getName() << " | New weight: " << animal1.feed(*days1) << endl;
	cout << "ChangeName to " << *newName1 << " | New name: " << animal1.changeName(*newName1) << endl;
	animal1.print();
	cout << endl;

	// -------
	// animal2
	// -------
	cout << endl;
	
	{
		Animal* animal2 = new Animal("Bobby", "dog", "white", 10);
		animal2->print();

		delete animal2;
	}

	// -------
	// animal3
	// -------
	cout << endl;
	
	Animal animal3("Fred", "hamster", "gray");
	animal3.print();

	// -------
	// animal4
	// -------
	cout << endl;

	{
		Animal* animal4 = new Animal("Piggy", "pig");
		animal4->print();
		
		// -------
		// animal5
		// -------
		cout << endl;

		Animal animal5("Hippo");
		animal5.print();

		delete animal4;
	}

	// -------
	// animal6
	// -------
	cout << endl;

	Animal* animal6 = new Animal();

	int* decreaseMileageAmount6 = new int;
	*decreaseMileageAmount6 = 2537;

	animal6->print();
	animal6->setName("Howard");
	animal6->setSpecies("elephant");
	
	animal6->setColor("light gray");
	
	animal6->setAge(7);
	cout << "Current weight: " << animal6->getWeight() << endl;
	animal6->setWeight(-654);
	cout << "Current weight: " << animal6->getWeight() << endl;
	animal6->setWeight(1465);
	

	// перегрузы
	cout << endl << "*** перегрузы ***" << endl << endl;

	animal3.setWeight(6.1);
	cout << animal1;
	cout << animal3;

	if (animal1 > animal3) {
		cout << "animal1 weight is more than animal3 weight" << endl;
	} else if (animal1 < animal3) {
		cout << "animal3 weight is more than animal1 weight" << endl;
	} else {
		cout << "animal3 weight is equal to animal1 weight" << endl;
	}

	for(unsigned i = 0; i < 5; ++i) {
		--(animal1);
		++animal3;
	}
	cout << endl << animal3;
	cout << animal1 << endl;

	if (animal1 > animal3) {
		cout << "animal1 weight is more than animal3 weight" << endl;
	} else if (animal1 < animal3) {
		cout << "animal3 weight is more than animal1 weight" << endl;
	} else {
		cout << "animal3 weight is equal to animal1 weight" << endl;
	}

	{
		cout << endl << animal1;
		Animal testDecrementReturn1 = --(animal1);
		cout << testDecrementReturn1;
		Animal testDecrementReturn2 = --(animal1);
		cout << testDecrementReturn2;
	}

	delete animal6;

	delete days1;
	delete newName1;

	// enum и namespace
	cout << endl << "*** enum и namespace ***" << endl << endl;

	Animal* dogHuski = new Animal("AAAA", "dog", "lightgray", age::dogHuski);
	Animal* dogAlabay = new Animal("BBBB", "dog", "white", age::dogAlabay);
	Animal* dogShepherd = new Animal("CCCC", "dog", "brown", age::dogShepherd);

	cout << endl << *dogHuski << *dogAlabay << *dogShepherd << endl;


	delete dogHuski;
	delete dogAlabay;
	delete dogShepherd;

	return 0;
}
