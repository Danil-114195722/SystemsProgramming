#include <iostream>
#include "./Inspector.h"

using namespace std;


// конструкторы
Inspector::Inspector(string firstName, string lastName, string phone, int age, int experience) :
	IPerson(firstName, lastName), Client(firstName, lastName, phone), Employee(firstName, lastName, age, experience, 0) {}

// деструктор
Inspector::~Inspector() {
	// cout << "___ ~Destr Inspector " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// методы

void Inspector::print(string prefix) {
	cout << prefix << "Inspector: " << this->getFirstName() << " " << this->getLastName()
		<< " | Phone: " << this->getPhone()
		<< " | Age: " << this->getAge()
		<< " | Experience: " << this->getExperience()
		<< endl;
}
