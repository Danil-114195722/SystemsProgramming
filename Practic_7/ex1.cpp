#include <iostream>


int square(int num) {
	return num * num;
}


int main() {
	int inputNum;

	std::cout << "Enter the number: ";
	std::cin >> inputNum;

	std::cout << "Square of " << inputNum << " = " << square(inputNum) << std::endl;

	return 0;
}

