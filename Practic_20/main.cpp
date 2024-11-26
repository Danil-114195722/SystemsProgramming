#include <iostream>
#include <fstream>
#include "./human/Student.h"

using namespace std;


int main() {
	int objAmount;
	cout << "Enter amount of objects to create: ";
	cin >> objAmount;
	IHuman** peoples = new IHuman*[objAmount];

	int objType;
	for(int i = 0; i < objAmount; ++i) {
		cout << "Enter type of " << i+1 << " object [1 - Child; 2 - Adult; 3 - Student]: ";
		cin >> objType;

		switch (objType) {
			case 1:
				peoples[i] = new Child;
				break;
			case 2:
				peoples[i] = new Adult;
				break;
			case 3:
				peoples[i] = new Student;
				break;
			default:
				break;
		}

		peoples[i]->readFromConsole();
	}

	ofstream out("Peolpes.txt", ios::out | ios::trunc);

	for(int i = 0; i < objAmount; ++i) {
		peoples[i]->print();
		peoples[i]->writeToFile();
		cout << peoples[i]->getFirstName() << " " << peoples[i]->getLastName() << " was saved to file!" << endl;
	}
	delete peoples;

	return 0;
}
