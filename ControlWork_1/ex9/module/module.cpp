// module.cpp

#include <iostream>
#include "module.h"


bool Contains(int* arr, int size, int num) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == num) {
			return true;
		}
	}
	return false;
}
bool Contains(double* arr, int size, double num) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == num) {
			return true;
		}
	}
	return false;
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
