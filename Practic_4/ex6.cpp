#include <iostream>


int main() {
	int size = 5;
	int *arr = new int[size];
	int sum = 0;

	int num;
	for(unsigned i = 0; i < size; ++i) {
		std::cout << "Enter the number [left " << size - i << "]: ";
		std::cin >> num;
		arr[i] = num;
	}

	for(unsigned i = 0; i < size; ++i) {
		sum += arr[i];
	}

	delete[] arr;

	std::cout << "Sum of nums: " << sum << std::endl;

	return 0;
}
