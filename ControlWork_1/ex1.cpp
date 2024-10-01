#include <iostream>


int main() {
	int array[7] = {2, 3, 4, 5, 2, 8, 10};

	std::cout << "array[7] = [ ";
	for (int i = 0; i < 7; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "]" << std::endl;

	return 0;
}
