#define SIZE 5
#include <iostream>
#include "my_package/funcs.h"


int main() {
	int* array = new int[SIZE];

	for (int i = 0; i < SIZE; ++i) {
		std::cout << "Enter number " << i + 1 << ": ";
		std::cin >> array[i];
	}

	std::cout << "array = [ ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "countOdd = " << countOdd(array, SIZE) << std::endl;
	delete[] array;

	return 0;
}
