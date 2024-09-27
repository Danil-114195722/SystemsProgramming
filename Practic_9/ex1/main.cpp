#include <iostream>
#include "module.h"


int main() {
	// ---------
	// int array
	// ---------

	int intArrSize;
	std::cout << "Enter intArr size: ";
	std::cin >> intArrSize;

	int* intArr = new int[intArrSize];
	readArr(intArr, intArrSize);
	printArr(intArr, intArrSize);

	int* duplicatedIntArr = new int[intArrSize];
	copyArray(intArr, duplicatedIntArr, intArrSize);
	std::cout << "duplicated ";
	printArr(duplicatedIntArr, intArrSize);

	// ------------
	// double array
	// ------------

	int doubleArrSize;
	std::cout << "Enter doubleArr size: ";
	std::cin >> doubleArrSize;

	double* doubleArr = new double[doubleArrSize];
	readArr(doubleArr, doubleArrSize);
	printArr(doubleArr, doubleArrSize);


	double* duplicatedDoubleArr = new double[doubleArrSize];
	copyArray(doubleArr, duplicatedDoubleArr, doubleArrSize);
	std::cout << "duplicated ";
	printArr(duplicatedDoubleArr, doubleArrSize);

	delete[] intArr;
	delete[] doubleArr;
	delete[] duplicatedIntArr;
	delete[] duplicatedDoubleArr;

	return 0;
}

