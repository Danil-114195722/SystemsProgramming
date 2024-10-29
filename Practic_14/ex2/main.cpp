#include <iostream>
#include "Car.h"

using namespace std;


int main() {
	// ----
	// car1
	// ----
	cout << endl;

	Car* car1 = new Car("Lada", "blue", "universal", 1.5, 34654);

	int* decreaseMileageAmount1 = new int;
	*decreaseMileageAmount1 = 50;

	car1->print();
	cout << "AverageFuelConsumption: " << car1->averageFuelConsumption() << endl;
	cout << "DecreaseMileage on " << *decreaseMileageAmount1 << " | New mileage: " << car1->decreaseMileage(*decreaseMileageAmount1) << endl;

	// ----
	// car2
	// ----
	cout << endl;
	
	{
		Car car2("Ford", "gray", "hatchback", 1.8, 645865);
		
		int* decreaseMileageAmount2 = new int;
		*decreaseMileageAmount2 = 568;

		car2.print();
		cout << "AverageFuelConsumption: " << car2.averageFuelConsumption() << endl;
		cout << "DecreaseMileage on " << *decreaseMileageAmount2 << " | New mileage: " << car2.decreaseMileage(*decreaseMileageAmount2) << endl;
		
		delete decreaseMileageAmount2;
	}

	// ----
	// car3
	// ----
	cout << endl;
	
	Car car3("Porsche", "yellow", "sedan");

	int* decreaseMileageAmount3 = new int;
	*decreaseMileageAmount3 = 477;

	car3.print();
	cout << "AverageFuelConsumption: " << car3.averageFuelConsumption() << endl;
	cout << "DecreaseMileage on " << *decreaseMileageAmount3 << " | New mileage: " << car3.decreaseMileage(*decreaseMileageAmount3) << endl;
	

	// ----
	// car4
	// ----
	cout << endl;

	{
		Car* car4 = new Car("McLaren", "sky blue");
		
		int* decreaseMileageAmount4 = new int;
		*decreaseMileageAmount4 = 2537;
		
		car4->print();
		cout << "AverageFuelConsumption: " << car4->averageFuelConsumption() << endl;
		cout << "DecreaseMileage on " << *decreaseMileageAmount4 << " | New mileage: " << car4->decreaseMileage(*decreaseMileageAmount4) << endl;

		// ----
		// car5
		// ----
		cout << endl;

		Car car5("Renaut");
		car5.print();

		delete car4;
		delete decreaseMileageAmount4;
	}

	delete car1;

	// ----
	// car6
	// ----
	cout << endl;

	Car* car6 = new Car();

	int* decreaseMileageAmount6 = new int;
	*decreaseMileageAmount6 = 2537;

	car6->print();
	car6->setBrend("Chevrolet Corvette");
	car6->setColor("orange");
	
	car6->setBodyType("smth");
	car6->print();
	car6->setBodyType("sedan");
	
	car6->setMotorCapacity(7);
	car6->setMileage(-6547);
	car6->print();
	car6->setMileage(6547);
	
	car6->print();
	cout << "AverageFuelConsumption: " << car6->averageFuelConsumption() << endl;
	cout << "DecreaseMileage on " << *decreaseMileageAmount6 << " | New mileage: " << car6->decreaseMileage(*decreaseMileageAmount6) << endl;


	delete car6;

	delete decreaseMileageAmount1;
	delete decreaseMileageAmount3;
	delete decreaseMileageAmount6;

	return 0;
}
