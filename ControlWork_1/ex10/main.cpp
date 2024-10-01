// main.cpp

#include <iostream>
#include "./module/module.h"


int main() {
	int size = 10;
	int* arr = new int[size]{4, 5, 3, 9, 19, 10, 25, 17, 32, 21};
	PrintArr(arr, size);

	bool (*evenCond)(int) = Even;
	int sumEven = CondSum(arr, size, Even);
	std::cout << "Сумма чётных элементов: " << sumEven << std::endl;

	delete[] arr;

	return 0;
}
