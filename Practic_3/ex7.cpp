#include <iostream>


int main() {
	bool is_prime = true;
	int n;

	std::cout << "Enter number: ";
	std::cin >> n;

	for (int i = 2; i <= (n - 1); i++) {
		if (n % i == 0) {
			is_prime = false;
			break;
		}
	}

	if(is_prime) {
		std::cout << "Число простое" << std::endl;
	} else {
		std::cout << "Число сложное" << std::endl;
	}

	return 0;
}
