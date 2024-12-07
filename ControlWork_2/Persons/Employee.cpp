#include <iostream>
#include "./Employee.h"

using namespace std;


// конструкторы
Employee::Employee(string firstName, string lastName, int age, int experience, int salary) :
	IPerson(firstName, lastName), _age(age), _experience(experience), _salary(salary) {}

// деструктор
Employee::~Employee() {
	// cout << "___ ~Destr Employee " << this->getFirstName() << " " << this->getLastName() << " ___" << endl;
}

// геттеры

int Employee::getAge() {
	return this->_age;
}

int Employee::getExperience() {
	return this->_experience;
}

int Employee::getSalary() {
	return this->_salary;
}

// методы

void Employee::print(string prefix) {
	cout << prefix << "Employee: " << this->getFirstName() << " " << this->getLastName()
		<< " | Age: " << this->_age
		<< " | Experience: " << this->_experience
		<< " | Salary: " << this->_salary
		<< endl;
}
