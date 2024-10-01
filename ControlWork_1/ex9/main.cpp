// main.cpp

#include <iostream>
#include "./module/module.h"

int main() {
	int intArr[] = {3, 7, 11, 16, 23};
	int intSize = sizeof(intArr) / sizeof(intArr[0]);
	PrintArr(intArr, intSize);

	int intNum = 3;
	std::cout << intNum << " in intArr: " << std::boolalpha << Contains(intArr, intSize, intNum) << std::endl;
	intNum = 9;
	std::cout << intNum << " in intArr: " << std::boolalpha << Contains(intArr, intSize, intNum) << std::endl;

	std::cout << std::endl;


	double doubleArr[] = {36.21, 33.6, 9.7, 2.0, 41.08};
	int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
	PrintArr(doubleArr, doubleSize);

	double doubleNum = 33.6;
	std::cout << doubleNum << " in doubleArr: " << std::boolalpha << Contains(doubleArr, doubleSize, doubleNum) << std::endl;
	doubleNum = 8.08;
	std::cout << doubleNum << " in doubleArr: " << std::boolalpha << Contains(doubleArr, doubleSize, doubleNum) << std::endl;

	return 0;
}
