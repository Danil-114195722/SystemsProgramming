#include <iostream>


int main() {

	int n;

	std::cout << "Enter number: ";
	std::cin >> n;

	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0) {
			std::cout << i << " ";
		}
	}
	std::cout << std::endl;

	return 0;
}
