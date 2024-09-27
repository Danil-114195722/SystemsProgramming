#include <iostream>
#include "module.h"


int main() {
	int size = 10;
	int* arr = new int[size]{4, 65, 34, 9, 93, 100, 45, 77, 36, 10};
	PrintArr(arr, size);

	bool (*maxExpression)(int, int) = Max;
	int max = FindElem(arr, size, maxExpression);
	std::cout << "Max elem: " << max << std::endl;

	bool (*minExpression)(int, int) = Min;
	int min = FindElem(arr, size, minExpression);
	std::cout << "Min elem: " << min << std::endl;

	delete[] arr;

	return 0;
}

