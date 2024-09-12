#include <iostream>


int main() {
	const int size = 10;
	int arr[size] = {6, 8, 21, 28, 33, 32, 49, 50, 56, 70};

	int num;
	std::cout << "Enter the number: ";
	std::cin >> num;

	int count = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % num == 0) {
			count++;
		}
	}
	std::cout << "Count of multiplies of the number: " << count << std::endl;

	return 0;
}

