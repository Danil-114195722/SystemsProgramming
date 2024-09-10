#include <iostream>


int main() {
	int sum = 0;

	for (int i = 1; i <= 100; i++) {
		sum += i;
		if (sum >= 1000) {
			break;
		}
	}

	std::cout << "Sum: " << sum << std::endl;

	return 0;
}
