#include <iostream>


int main() {
	int size = 7;

	int array[size] = {2, 3, 4, 5, 2, 8, 10};

	for (int i = 0; i < size; i++) {
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}

	return 0;
}
