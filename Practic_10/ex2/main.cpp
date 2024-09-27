#include <iostream>
#include "module.h"


int main() {
	int size = 10;
	int* arr = new int[size]{4, 65, 34, 9, 93, 100, 45, 77, 36, 10};
	PrintArr(arr, size);

	bool (*oddCond)(int) = Odd;
	int sumOdd = SumWithCondition(arr, size, oddCond);
	std::cout << "Sum odd elems: " << sumOdd << std::endl;

	bool (*evenCond)(int) = Even;
	int sumEven = SumWithCondition(arr, size, Even);
	std::cout << "Sum even elems: " << sumEven << std::endl;

	delete[] arr;

	return 0;
}

