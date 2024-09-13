#define SIZE 5
#include <iostream>


void printArr(int arr[SIZE]) {
	std::cout << "arr: [ ";
	for(unsigned i = 0; i < SIZE; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;;
}


int main() {
	int arr[SIZE] = {1, 2, 3, 4, 5};
	int* tempArr = new int[SIZE];

	printArr(arr);

	for(unsigned i = 0; i < SIZE; ++i) {
		tempArr[i] = arr[SIZE-1-i];
	}
	for(unsigned i = 0; i < SIZE; ++i) {
		arr[i] = tempArr[i];
	}
	delete[] tempArr;

	printArr(arr);

	return 0;
}
