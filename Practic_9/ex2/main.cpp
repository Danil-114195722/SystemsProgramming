#include <iostream>
#include "module.h"


int main() {
	// ---------
	// int array
	// ---------

	int intArr[] = {1, 2, 3, 4, 5};
	int intSize = sizeof(intArr) / sizeof(intArr[0]);
	PrintArr(intArr, intSize);

	int intNum = 3;
	std::cout << intNum << " in intArr: " << Contains(intArr, intSize, intNum) << std::endl;
	intNum = 99;
	std::cout << intNum << " in intArr: " << Contains(intArr, intSize, intNum) << std::endl;

	std::cout << std::endl;

	// ------------
	// double array
	// ------------

	double doubleArr[] = {53.231, 83.6, 3.0, 4.21, 5.98};
	int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
	PrintArr(doubleArr, doubleSize);

	double doubleNum = 3.6;
	std::cout << doubleNum << " in doubleArr: " << Contains(doubleArr, doubleSize, doubleNum) << std::endl;
	doubleNum = 83.6;
	std::cout << doubleNum << " in doubleArr: " << Contains(doubleArr, doubleSize, doubleNum) << std::endl;

	return 0;
}

