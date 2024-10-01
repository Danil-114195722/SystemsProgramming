#define SIZE 5
#include <iostream>

int countOdd(int* arr, int size) {
	int count = 0;

	for(int i = 0; i < size; ++i) {
		if(arr[i] % 2 == 0) {
			count++;
		}
	}
	return count;
}

int main() {
	int* array = new int[SIZE];

	for (int i = 0; i < SIZE; ++i) {
		std::cout << "Введите число " << i + 1 << ": ";
		std::cin >> array[i];
	}

	std::cout << "array = [ ";
	for (int i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "]" << std::endl;

	std::cout << "Кол-во чётных элементов: " << countOdd(array, SIZE) << std::endl;
	delete[] array;

	return 0;
}
