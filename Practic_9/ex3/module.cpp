#include <iostream>
#include "module.h"


void ResizeArray(int* arr, int size, int* resizedArr, int newSize) {
	if (size <= newSize) {
		for (int i = 0; i < size; ++i) {
			resizedArr[i] = arr[i];
		}
	} else {
		for (int i = 0; i < newSize; ++i) {
			resizedArr[i] = arr[i];
		}
	}
}
void ResizeArray(double* arr, int size, double* resizedArr, int newSize) {
	if (size <= newSize) {
		for (int i = 0; i < size; ++i) {
			resizedArr[i] = arr[i];
		}
	} else {
		for (int i = 0; i < newSize; ++i) {
			resizedArr[i] = arr[i];
		}
	}
}


void PrintArr(int* arr, int size) {
	std::cout << "intArr = [ ";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}
void PrintArr(double* arr, int size) {
	std::cout << "doubleArr = [ ";
	for(int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}