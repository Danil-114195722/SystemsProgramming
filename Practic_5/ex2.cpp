#include <iostream>


int main() {
	int arr[5];

	// ERROR!!!
	// for(int i = 0; i <= 5; i++) {
	for(int i = 0; i < 5; i++) {
		arr[i] = i * 2;
		std::cout << arr[i] << " ";
	}

	// std::cout << std::endl << arr[5];
	// std::cout << std::endl << sizeof(arr) / sizeof(arr[0]);

	std::cout << std::endl;

	return 0;
}

