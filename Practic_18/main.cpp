#include <iostream>

#include "./human/Human.h"
#include "./human/enums.h"
#include "./human/Child.h"
#include "./human/Adult.h"

using namespace std;


int main() {
	Child* child1 = new Child("Jim", "Hawkins", 14, 50, 1.65, "School №33");
	Child child2("Jim", "Hawkins", 14, 50, 1.65, "School №33");
	Adult* adult1 = new Adult("Ivan", "Verov", 41, 80, 1.85, "PAO \"Rostelecom\"");
	Adult adult2("Chester", "Bennington", human::age::chester, 70, 1.8, "Warner Bros. Records");

	Human** peoples = new Human*[4]{child1, &child2, adult1, &adult2};

	for (int i = 0; i < 4; ++i) {
		peoples[i]->print();
	}

	delete child1;
	delete adult1;

	return 0;
}
