#define CURRENT_YEAR 2024
#include <iostream>


struct Human {
	std::string first_name;
	std::string last_name;
	int age;
	float weight;
	float height;

	void print() {
		std::cout << "Human: " << first_name << " " << last_name;
		std::cout << " | Age: " << age << " | Weight: " << weight << " | height: " << height << std::endl;
	};

	float bodyWeightIndex() {
		return weight / (height * height);
	};

	int bornYear() {
		return CURRENT_YEAR - age;
	};
};


float BodyWeightIndex(Human human) {
	return human.weight / (human.height * human.height);
}

int GetBornYear(Human human) {
	return CURRENT_YEAR - human.age;
}

void PrintHuman(Human human) {
	std::cout << "Human: " << human.first_name << " " << human.last_name;
	std::cout << " | Age: " << human.age << " | Weight: " << human.weight << " | height: " << human.height << std::endl;
}


int main() {
	// ------
	// human1
	// ------

	Human human1;
	human1.first_name = "Bob";
	human1.last_name = "Marley";
	human1.age = 35;
	human1.weight = 71.4;
	human1.height = 1.85;

	PrintHuman(human1);
	std::cout << "BodyWeightIndex: " << BodyWeightIndex(human1) << std::endl;
	std::cout << "BornYear: " << GetBornYear(human1) << std::endl;
	human1.print();
	std::cout << "BodyWeightIndex: " << human1.bodyWeightIndex() << std::endl;
	std::cout << "BornYear: " << human1.bornYear() << std::endl;
	std::cout << std::endl;

	// ------
	// human2
	// ------
	
	Human human2 = {"Kurt", "Cobain", 27, 65, 1.8};
	PrintHuman(human2);
	std::cout << "BodyWeightIndex: " << BodyWeightIndex(human2) << std::endl;
	std::cout << "BornYear: " << GetBornYear(human2) << std::endl;
	human2.print();
	std::cout << "BodyWeightIndex: " << human2.bodyWeightIndex() << std::endl;
	std::cout << "BornYear: " << human2.bornYear() << std::endl;
	std::cout << std::endl;

	// ------
	// human3
	// ------
	
	Human human3{"Chester", "Bennington", 41, 67.3, 1.79};
	PrintHuman(human3);
	std::cout << "BodyWeightIndex: " << BodyWeightIndex(human3) << std::endl;
	std::cout << "BornYear: " << GetBornYear(human3) << std::endl;
	human3.print();
	std::cout << "BodyWeightIndex: " << human3.bodyWeightIndex() << std::endl;
	std::cout << "BornYear: " << human3.bornYear() << std::endl;
	std::cout << std::endl;

	// ------
	// human4
	// ------

	Human* human4 = new Human;
	(*human4).first_name = "Daniil";
	(*human4).last_name = "Dudkov";
	human4->age = 17;
	human4->weight = 65;
	human4->height = 1.77;
	
	PrintHuman(*human4);
	std::cout << "BodyWeightIndex: " << BodyWeightIndex(*human4) << std::endl;
	std::cout << "BornYear: " << GetBornYear(*human4) << std::endl;
	human4->print();
	std::cout << "BodyWeightIndex: " << human4->bodyWeightIndex() << std::endl;
	std::cout << "BornYear: " << human4->bornYear() << std::endl;
	std::cout << std::endl;

	delete human4;

	return 0;
}

