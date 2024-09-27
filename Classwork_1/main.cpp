#include <iostream>
#include "123.h"


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
	int sumIntArr = sumArr(intArr, intArrSize);
	std::cout << "Sum intArr = " << sumIntArr << std::endl;

	// ------------
	// double array
	// ------------

	int doubleArrSize;
	std::cout << "Enter doubleArr size: ";
	std::cin >> doubleArrSize;

	double* doubleArr = new double[doubleArrSize];
	readArr(doubleArr, doubleArrSize);
	printArr(doubleArr, doubleArrSize);
	int sumDoubleArr = sumArr(doubleArr, doubleArrSize);
	std::cout << "Sum doubleArr = " << sumDoubleArr << std::endl;

	delete[] intArr;
	delete[] doubleArr;

	return 0;
}
