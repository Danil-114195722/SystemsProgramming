#include <iostream>


void printArr(int* arr, int size) {
	std::cout << "array = [ ";
	for (int i = 0; i < size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}


void arrNumTransform(int& num, int* arr) {
	arr[num] = 0;
	num++;
}


int main() {
	int num = 7;
	int& numLink = num;
	int array[] = {22, 31, 4, 52, 36, 73, 90, 9, 43, 50};
	int size = sizeof(array) / sizeof(array[0]);

	printArr(array, size);
	std::cout << "Num: " << num << std::endl;
	std::cout << "NumLink: " << numLink << std::endl;

	std::cout << "Made transformations" << std::endl;
	arrNumTransform(num, array);

	printArr(array, size);
	std::cout << "Num: " << num << std::endl;
	std::cout << "NumLink: " << numLink << std::endl;

	return 0;
}
