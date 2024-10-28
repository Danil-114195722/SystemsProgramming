#include <iostream>


struct Animal {
	std::string name;
	std::string species;
	std::string color;
	int age;
	float weight;

	void Print() {
		std::cout << "Animal: " << name << " | Species: " << species;
		std::cout << " | Color: " << color << " | Age: " << age << " | Weight: " << weight << std::endl;
	};

	float Feed(int days) {
		weight += 0.01 * days;
		return weight;
	};

	std::string ChangeName(std::string newName) {
		name = newName;
		return newName;
	}
};


float Feed(Animal* animal, int days) {
	animal->weight += 0.01 * days;
	return animal->weight;
};

std::string ChangeName(Animal* animal, std::string newName) {
	animal->name = newName;
	return newName;
}

void PrintAnimal(Animal animal) {
	std::cout << "Animal: " << animal.name << " | Species: " << animal.species;
	std::cout << " | Color: " << animal.color << " | Age: " << animal.age << " | Weight: " << animal.weight << std::endl;
}


int main() {
	// -------
	// animal1
	// -------

	Animal animal1;
	animal1.name = "Peach";
	animal1.species = "cat";
	animal1.color = "sand";
	animal1.age = 4;
	animal1.weight = 6;

	std::string* newName1 = new std::string;
	*newName1 = "Peach 2.0";
	int* days1 = new int;
	*days1 = 5;

	PrintAnimal(animal1);
	std::cout << "Feed " << animal1.name << " | New weight: " << Feed(&animal1, *days1) << std::endl;
	std::cout << "ChangeName to " << *newName1 << " | New name: " << ChangeName(&animal1, *newName1) << std::endl;
	animal1.Print();
	std::cout << "Feed " << animal1.name << " | New weight: " << animal1.Feed(*days1) << std::endl;
	*newName1 = "Peach 3.0";
	std::cout << "ChangeName to " << *newName1 << " | New name: " << ChangeName(&animal1, *newName1) << std::endl;
	animal1.Print();
	std::cout << std::endl;

	// ------
	// animal2
	// -------
	
	Animal animal2 = {"Bobby", "dog", "white", 10, 8};

	std::string* newName2 = new std::string;
	*newName2 = "Bobby 2.0";
	int* days2 = new int;
	*days2 = 30;

	PrintAnimal(animal2);
	std::cout << "Feed " << animal2.name << " | New weight: " << Feed(&animal2, *days2) << std::endl;
	std::cout << "ChangeName to " << *newName2 << " | New name: " << ChangeName(&animal2, *newName2) << std::endl;
	animal2.Print();
	std::cout << "Feed " << animal2.name << " | New weight: " << animal2.Feed(*days2) << std::endl;
	*newName2 = "Bobby 3.0";
	std::cout << "ChangeName to " << *newName2 << " | New name: " << animal2.ChangeName(*newName2) << std::endl;
	animal2.Print();
	std::cout << std::endl;

	// -------
	// animal3
	// -------
	
	Animal animal3{"Fred", "hamster", "gray", 1, 0.5};

	std::string* newName3 = new std::string;
	*newName3 = "Fred 2.0";
	int* days3 = new int;
	*days3 = 200;

	PrintAnimal(animal3);
	std::cout << "Feed " << animal3.name << " | New weight: " << Feed(&animal3, *days3) << std::endl;
	std::cout << "ChangeName to " << *newName3 << " | New name: " << ChangeName(&animal3, *newName3) << std::endl;
	animal3.Print();
	std::cout << "Feed " << animal3.name << " | New weight: " << animal3.Feed(*days3) << std::endl;
	*newName3 = "Fred 3.0";
	std::cout << "ChangeName to " << *newName3 << " | New name: " << ChangeName(&animal3, *newName3) << std::endl;
	animal3.Print();
	std::cout << std::endl;

	// -------
	// animal4
	// -------

	Animal* animal4 = new Animal;
	(*animal4).name = "Pig";
	(*animal4).species = "pig";
	animal4->color = "pink";
	animal4->age = 3;
	animal4->weight = 20.6;

	std::string* newName4 = new std::string;
	*newName4 = "Pig 2.0";
	int* days4 = new int;
	*days4 = 365;
	
	PrintAnimal(*animal4);
	std::cout << "Feed " << animal4->name << " | New weight: " << Feed(animal4, *days4) << std::endl;
	std::cout << "ChangeName to " << *newName4 << " | New name: " << ChangeName(animal4, *newName4) << std::endl;
	animal4->Print();
	std::cout << "Feed " << animal4->name << " | New weight: " << animal4->Feed(*days4) << std::endl;
	*newName4 = "Pig 3.0";
	std::cout << "ChangeName to " << *newName4 << " | New name: " << ChangeName(animal4, *newName4) << std::endl;
	animal4->Print();
	std::cout << std::endl;


	delete newName1;
	delete newName2;
	delete newName3;
	delete newName4;

	delete days1;
	delete days2;
	delete days3;
	delete days4;
	
	delete animal4;

	return 0;
}

