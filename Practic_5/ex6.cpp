#include <iostream>


int main() {
	float y = 3.14;
	char myChar = 'A';
	bool isTrue = true;
	
	int x;
	std::cout << "Enter \"x\" value: ";
	std::cin >> x;

	if (x > 5) {
		std::cout << "x is greater than 5" << std::endl;
	} else {
		std::cout << "x is less or equal to 5" << std::endl;
	}

	std::cout << "Value of y: " << y << std::endl;
	std::cout << "Character: " << myChar << std::endl;
	std::cout << "Boolean: " << isTrue << std::endl;
	
	return 0;
}

