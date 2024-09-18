#include <iostream>

#include <cmath>
#include <stdlib.h>


double sqrti(double num) {
	if (num < 0) {
		std::cout << "TypeError: Negative argument" << std::endl;
		exit(5);
	}

	return sqrt(num);
}


int main() {
	double inputNum;

	std::cout << "Enter the number: ";
	std::cin >> inputNum;

	double sqrtNum = sqrti(inputNum);
	std::cout << "Square root of " << inputNum << " = " << sqrtNum << std::endl;

	return 0;
}
