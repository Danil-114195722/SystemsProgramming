#include <iostream>
#include "Car.h"
#include "enums.h"

using namespace std;


int main() {
	// ----
	// car1
	// ----
	cout << endl;

	Car* car1 = new Car("Lada", "blue", "universal", 1.5, 34654);

	int* decreaseMileageAmount1 = new int;
	*decreaseMileageAmount1 = 50;

	cout << *car1;
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

		cout << car2;
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

	cout << car3;
	cout << car3;
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
		
		cout << *car4;
		cout << "AverageFuelConsumption: " << car4->averageFuelConsumption() << endl;
		cout << "DecreaseMileage on " << *decreaseMileageAmount4 << " | New mileage: " << car4->decreaseMileage(*decreaseMileageAmount4) << endl;

		// ----
		// car5
		// ----
		cout << endl;

		Car car5("Renaut");
		cout << car5;

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

	cout << *car6;
	car6->setBrend("Chevrolet Corvette");
	car6->setColor("orange");
	
	car6->setBodyType("smth");
	cout << *car6;
	car6->setBodyType("sedan");
	
	car6->setMotorCapacity(7);
	car6->setMileage(-6547);
	cout << *car6;
	car6->setMileage(6547);
	
	cout << *car6;
	cout << "AverageFuelConsumption: " << car6->averageFuelConsumption() << endl;
	cout << "DecreaseMileage on " << *decreaseMileageAmount6 << " | New mileage: " << car6->decreaseMileage(*decreaseMileageAmount6) << endl;


	// перегрузы
	cout << endl << "*** перегрузы ***" << endl << endl;

	car3.setMotorCapacity(6.1);
	cout << car3;

	if (*car6 > car3) {
		cout << "car6 motorCapacity is more than car3 motorCapacity" << endl;
	} else if (*car6 < car3) {
		cout << "car3 motorCapacity is more than car6 motorCapacity" << endl;
	} else {
		cout << "car3 motorCapacity is equal to car6 motorCapacity" << endl;
	}

	for(unsigned i = 0; i < 5; ++i) {
		--(*car6);
		++car3;
	}
	cout << endl << car3;
	cout << *car6 << endl;

	if (*car6 > car3) {
		cout << "car6 motorCapacity is more than car3 motorCapacity" << endl;
	} else if (*car6 < car3) {
		cout << "car3 motorCapacity is more than car6 motorCapacity" << endl;
	} else {
		cout << "car3 motorCapacity is equal to car6 motorCapacity" << endl;
	}

	delete car6;

	delete decreaseMileageAmount1;
	delete decreaseMileageAmount3;
	delete decreaseMileageAmount6;

	// enum и namespace
	cout << endl << "*** enum и namespace ***" << endl << endl;

	Car* lada = new Car("Lada", "white", "sedan", 1.5, car::mileage::lada);
	Car* chevrolet = new Car("Chevrolet", "orange", "sedan", 4.6, car::mileage::chevrolet);
	Car* chery = new Car("Chery", "red", "universal", 3.3, car::mileage::chery);

	cout << endl << *lada << *chevrolet << *chery << endl;

	lada->setMileage(car::mileage::chery);
	cout << *lada;

	delete lada;
	delete chevrolet;
	delete chery;

	return 0;
}
