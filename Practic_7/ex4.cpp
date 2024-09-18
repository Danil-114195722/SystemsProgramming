#define SIZE 10
#include <iostream>
#include "my_package/funcs.h"


int main() {
	int array[SIZE] = {0, 1, 11, 3, 4, 5, 6, 7, 8, 9};


	std::cout << "array = [ ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "countOdd = " << countOdd(array, SIZE) << std::endl;

	return 0;
}
