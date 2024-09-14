#include <iostream>


int main() {
	unsigned int uVal = 10;
	signed int sVal = -20;
	std::cout << "Unsigned Value: " << uVal << std::endl;
	std::cout << "Signed Value: " << sVal << std::endl;

	int user_input;
	std::cout << "Enter a number: ";
	std::cin >> user_input;

	if (user_input < 0) {
		std::cout << "Negative number!" << std::endl;
	} else if (user_input == 0) {
		std::cout << "Zero!" << std::endl;
	} else {
		std::cout << "Positive number!" << std::endl;
	}

	return 0;
}

