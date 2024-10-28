#include <iostream>


struct Car {
	std::string brend;
	std::string color;
	std::string bodyType;
	float motorCapacity;
	int mileage;

	void Print() {
		std::cout << "Car: " << brend << " | Color: " << color;
		std::cout << " | BodyType: " << bodyType << " | MotorCapacity: " << motorCapacity;
		std::cout << " | Mileage: " << mileage << std::endl;
	};

	float AverageFuelConsumption() {
		return motorCapacity / mileage * 100;
	};

	int DecreaseMileage(int amount) {
		mileage -= amount;
		if (mileage < 0) {
			mileage = 0;
		}
		return mileage;
	};
};


float AverageFuelConsumption(Car car) {
	return car.motorCapacity / car.mileage * 100;
}

int DecreaseMileage(Car* car, int amount) {
	car->mileage -= amount;
	if (car->mileage < 0) {
		car->mileage = 0;
	}
	return car->mileage;
}

void PrintCar(Car car) {
	std::cout << "Car: " << car.brend << " | Color: " << car.color;
	std::cout << " | BodyType: " << car.bodyType << " | MotorCapacity: " << car.motorCapacity;
	std::cout << " | Mileage: " << car.mileage << std::endl;
}


int main() {
	// ----
	// car1
	// ----

	Car car1;
	car1.brend = "Lada";
	car1.color = "blue";
	car1.bodyType = "universal";
	car1.motorCapacity = 1.4;
	car1.mileage = 34654;

	int* decreaseMileageAmount1 = new int;
	*decreaseMileageAmount1 = 50;

	PrintCar(car1);
	std::cout << "AverageFuelConsumption: " << AverageFuelConsumption(car1) << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount1 << " | New mileage: " << DecreaseMileage(&car1, *decreaseMileageAmount1) << std::endl;
	car1.Print();
	std::cout << "AverageFuelConsumption: " << car1.AverageFuelConsumption() << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount1 << " | New mileage: " << car1.DecreaseMileage(*decreaseMileageAmount1) << std::endl;
	car1.Print();
	std::cout << std::endl;

	// ----
	// car2
	// ----
	
	Car car2 = {"Ford", "gray", "hatchback", 1.8, 645865};
	
	int* decreaseMileageAmount2 = new int;
	*decreaseMileageAmount2 = 568;

	PrintCar(car2);
	std::cout << "AverageFuelConsumption: " << AverageFuelConsumption(car2) << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount2 << " | New mileage: " << DecreaseMileage(&car2, *decreaseMileageAmount2) << std::endl;
	car2.Print();
	std::cout << "AverageFuelConsumption: " << car2.AverageFuelConsumption() << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount2 << " | New mileage: " << car2.DecreaseMileage(*decreaseMileageAmount2) << std::endl;
	car2.Print();
	std::cout << std::endl;

	// ----
	// car3
	// ----
	
	Car car3{"Porsche", "yellow", "sedan", 3.8, 1676};

	int* decreaseMileageAmount3 = new int;
	*decreaseMileageAmount3 = 477;

	PrintCar(car3);
	std::cout << "AverageFuelConsumption: " << AverageFuelConsumption(car3) << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount3 << " | New mileage: " << DecreaseMileage(&car3, *decreaseMileageAmount3) << std::endl;
	car3.Print();
	std::cout << "AverageFuelConsumption: " << car3.AverageFuelConsumption() << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount3 << " | New mileage: " << car3.DecreaseMileage(*decreaseMileageAmount3) << std::endl;
	car3.Print();
	std::cout << std::endl;

	// ----
	// car4
	// ----

	Car* car4 = new Car;
	(*car4).brend = "McLaren";
	(*car4).color = "sky blue";
	car4->bodyType = "sedan";
	car4->motorCapacity = 6.1;
	car4->mileage = 754859;

	int* decreaseMileageAmount4 = new int;
	*decreaseMileageAmount4 = 2537;
	
	PrintCar(*car4);
	std::cout << "AverageFuelConsumption: " << AverageFuelConsumption(*car4) << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount4 << " | New mileage: " << DecreaseMileage(car4, *decreaseMileageAmount4) << std::endl;
	car4->Print();
	std::cout << "AverageFuelConsumption: " << car4->AverageFuelConsumption() << std::endl;
	std::cout << "DecreaseMileage on " << *decreaseMileageAmount4 << " | New mileage: " << car4->DecreaseMileage(*decreaseMileageAmount4) << std::endl;
	car4->Print();
	std::cout << std::endl;

	delete decreaseMileageAmount1;
	delete decreaseMileageAmount2;
	delete decreaseMileageAmount3;
	delete decreaseMileageAmount4;
	delete car4;

	return 0;
}

