#include <iostream>


int main() {
	int power = 1;
	int num = 2;


	for (int i = 0; i < 10; i++) {
		power *= num;
	}

	std::cout << "Result: " << power << std::endl;

	return 0;
}
