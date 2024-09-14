#include <iostream>


int main() {
	int numArray[5];
	for(int i = 0; i < 5; i++) {
		numArray[i] = i * 2;
	}

	int sum = 0;

	std::cout << "Array values: " << std::endl;
	for(int i = 0; i < 5; i++) {
		std::cout << "Element " << i << ": " << numArray[i] << std::endl;
		sum += numArray[i];
	}

	std::cout << "Sum = " << sum<< std::endl;

	return 0;
}

