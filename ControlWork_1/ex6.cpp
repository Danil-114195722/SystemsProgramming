#include <iostream>


int sum(int* arr, int n) {
	return n + arr[n];
}


int main() {
	int size;
	std::cout << "Введите размер массива: ";
	std::cin >> size;

	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		std::cout << "Введите число (элемент массива) [осталось " << size-i << "]: ";
		std::cin >> arr[i];
	}

	int num;
	std::cout << "Введите число n (меньше размера массива): ";
	std::cin >> num;

	if (num - 1 > size) {
		std::cout << "ОШИБКА: число n больше/равно размера массива!" << std::endl;
		return 1;
	}

	std::cout << "Сумма числа n и n-го элемента массива: " << sum(arr, num) << std::endl;

	delete[] arr;

	return 0;
}
