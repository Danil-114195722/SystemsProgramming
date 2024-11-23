#include <iostream>

#include "./human/Human.h"
#include "./human/enums.h"
#include "./human/Child.h"
#include "./human/Adult.h"

using namespace std;


int main() {
	Child* child1 = new Child("Jim", "Hawkins", 14, 50, 1.65, "School №33");
	Child child2("Karl", "Gallager", 16, 60, 1.7, "High School");
	Adult* adult1 = new Adult("Ivan", "Verov", 41, 80, 1.85, "PAO \"Rostelecom\"");
	Adult adult2("Chester", "Bennington", human::age::chester, 70, 1.8, "Warner Bros. Records");

	IHuman** peoples = new IHuman*[4]{child1, &child2, adult1, &adult2};

	char action = '5';
	while (action != '0') {
		cout << "Choose the human: 1 - Jim; 2 - Karl; 3 - Ivan; 4 - Chester; 5 - all of them: ";
		cin >> action;

		switch (action) {
			case '1':
				peoples[0]->print();
				break;
			case '2':
				peoples[1]->print();
				break;
			case '3':
				peoples[2]->print();
				break;
			case '4':
				peoples[3]->print();
				break;
			case '5':
				for (int i = 0; i < 4; ++i) {
					peoples[i]->print();
				}
				break;
			default:
				action = '0';
				break;
		}
		cout << endl;
	}

	delete child1;
	delete adult1;

	return 0;
}
