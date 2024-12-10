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

	if (objAmount == 0) {
		cout << "Goodbye!" << endl;
		return 0;
	}
	cout << "\nAll data was initialized successfully." << endl;

	int action = 0;
	while(action != -1) {
	    cout << "\nEnter action from list below:" << endl;
	    cout << "\t Index 0 for print out info about first Human" << endl;
	    if (objAmount > 1) {
		    cout << "\t Index 1 for print out info about second Human" << endl;
	    }
	    if (objAmount > 3) {
		    cout << "\t ..." << endl;
	    }
	    if (objAmount > 2) {
		    cout << "\t Index " << objAmount-1 << " for print out info about last Human" << endl;
	    }
	    if (objAmount > 1) {
		    cout << "\t Number " << objAmount << " for print out info about all of peoples" << endl;
	    }
	    cout << "\t Number -1 for print out info about all of peoples into file Peolpes.txt and exit from program" << endl;
	    
	    cout << "Choose action: ";
	    cin >> action;
	    cout << endl;

	    if (action == objAmount) {
	    	for(int i = 0; i < objAmount; ++i) {
				peoples[i]->print();
			}
	    } else if (action > objAmount || action < 0) {
	    	if (action != -1) {
		    	cout << "ERROR! Invalid index was given" << endl;
	    	}
	    } else {
	    	peoples[action]->print();
	    }
	}

	ofstream out("Peolpes.txt", ios::out | ios::trunc);
	for(int i = 0; i < objAmount; ++i) {
		peoples[i]->writeToFile();
	}
	cout << "All peoples was saved to file!" << endl;
	
	delete[] peoples;

	return 0;
}
