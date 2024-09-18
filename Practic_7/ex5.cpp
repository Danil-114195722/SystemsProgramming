#include <iostream>
#include "my_package/funcs.h"


int main() {
	int num = 9;

	int array[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 20};
	int arrSize = sizeof(array) / sizeof(array[0]);

	std::cout << "array = [ ";
	for (int i = 0; i < arrSize; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "]" << std::endl;
	std::cout << "Num: " << num << std::endl;

	std::cout << "sumArrNum = " << sumArrNum(num, array) << std::endl;

	return 0;
}
