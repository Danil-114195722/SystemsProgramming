#include <iostream>
#include "module.h"


// возврат true, если число нечётное
bool Odd(int num) {
	return num % 2 == 1;
}

// возврат true, если число чётное
bool Even(int num) {
	return num % 2 == 0;
}


// нахождение суммы элементов массива по условию переданной функции
int SumWithCondition(int* arr, int size, bool (*condition)(int)) {
	int sum = 0;
	for(int i = 0; i < size; ++i) {
		if ((*condition)(arr[i])) {
			sum += arr[i];
		}
	}
	return sum;
}


void PrintArr(int* arr, int size) {
	std::cout << "arr = [ ";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}
