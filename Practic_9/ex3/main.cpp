#include <iostream>
#include "module.h"
#define INIT_SIZE 5


int main() {
	// ---------
	// int array
	// ---------

	int* arr = new int[INIT_SIZE]{1, 2, 3, 4, 5};
	std::cout << "Init ";
	PrintArr(arr, INIT_SIZE);

	int newSize = 8;
	int* resizedArr = new int[newSize];
	ResizeArray(arr, INIT_SIZE, resizedArr, newSize);
	std::cout << "Resized (increase size) ";
	PrintArr(resizedArr, newSize);

	int newSize2 = 3;
	int* resizedArr2 = new int[newSize2];
	ResizeArray(arr, INIT_SIZE, resizedArr2, newSize2);
	std::cout << "Resized (decrease size) ";
	PrintArr(resizedArr2, newSize2);

	delete[] arr;
	delete[] resizedArr;
	delete[] resizedArr2;

	std::cout << std::endl;

	// ------------
	// double array
	// ------------

	double* arrD = new double[INIT_SIZE]{56.8, 23.6, 99.9, 71.2, 84.84};
	std::cout << "Init ";
	PrintArr(arrD, INIT_SIZE);

	int newSizeD = 10;
	double* resizedArrD = new double[newSizeD];
	ResizeArray(arrD, INIT_SIZE, resizedArrD, newSizeD);
	std::cout << "Resized (increase size) ";
	PrintArr(resizedArrD, newSize);

	int newSizeD2 = 2;
	double* resizedArrD2 = new double[newSizeD2];
	ResizeArray(arrD, INIT_SIZE, resizedArrD2, newSizeD2);
	std::cout << "Resized (decrease size) ";
	PrintArr(resizedArrD2, newSizeD2);

	delete[] arrD;
	delete[] resizedArrD;
	delete[] resizedArrD2;

	return 0;
}
