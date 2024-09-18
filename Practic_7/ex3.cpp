#include <iostream>

#include "my_package/funcs.h"


int main() {
	double inputNum1;
	std::cout << "Enter the first number: ";
	std::cin >> inputNum1;

	double inputNum2;
	std::cout << "Enter the second number: ";
	std::cin >> inputNum2;

	int inputAdd;
	std::cout << "Enter 1 to add or 2 to multiply the numbers above : ";
	std::cin >> inputAdd;

	if(inputAdd == 1) {
		std::cout << "Result: " << multiplyOrAdd(inputNum1, inputNum2) << std::endl;
	} else if (inputAdd == 2) {
		std::cout << "Result: " << multiplyOrAdd(inputNum1, inputNum2, false) << std::endl;
	} else {
		std::cout << "Invalid action!" << std::endl;
	}

	return 0;
}
