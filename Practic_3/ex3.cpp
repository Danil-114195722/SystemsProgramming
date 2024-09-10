#include <iostream>


int main() {
	int factorial = 1;
	int n;

	std::cout << "Enter number: ";
	std::cin >> n;

	while (n > 0) {
		factorial *= n;
		n--;
	}

	std::cout << "Factorial: " << factorial << std::endl;

	return 0;
}
