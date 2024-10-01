#define SIZE 10
#include <iostream>


int main() {
	int arr[SIZE] = {5, 4, 3, 24, 9, 21, 60, 32, 100, 1};

	int divider;
	std::cout << "Введите число: ";
	std::cin >> divider;

	int count = 0;
	for (int i = 0; i < SIZE; ++i) {
		if (arr[i] % divider == 0) {
			count++;
		}
	}
	std::cout << "Кол-во элементов, кратных введённому числу: " << count << std::endl;

	return 0;
}
