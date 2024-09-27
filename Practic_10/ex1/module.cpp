#include <iostream>
#include "module.h"


// возврат true, если первое число больше
bool Max(int num1, int num2) {
	if (num1 > num2) {
		return true;
	}
	return false;
}


// возврат true, если первое число меньше
bool Min(int num1, int num2) {
	if (num1 < num2) {
		return true;
	}
	return false;
}

// нахождение элемента в массиве по условию переданной функции
int FindElem(int* arr, int size, bool (*expression)(int, int)) {
	int foundElem = arr[0];
	for(int i = 1; i < size; ++i) {
		if ((*expression)(arr[i], foundElem)) {
			foundElem = arr[i];
		}
	}
	return foundElem;
}


void PrintArr(int* arr, int size) {
	std::cout << "arr = [ ";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}
