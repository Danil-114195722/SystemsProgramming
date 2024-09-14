#define SIZE 5
#include <iostream>


void printArr(int arr[SIZE]) {
	std::cout << "arr: [ ";
	for(unsigned i = 0; i < SIZE; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}


int main() {
	int* arr = new int[SIZE];
	int num;
	for(unsigned i = 0; i < SIZE; ++i) {
		std::cout << "Enter the number [left " << SIZE - i << "]: ";
		std::cin >> num;
		arr[i] = num;
	}
	printArr(arr);


	int* tempArr = new int[SIZE];
	for(unsigned i = 0; i < SIZE; ++i) {
		tempArr[i] = arr[SIZE-1-i];
	}
	for(unsigned i = 0; i < SIZE; ++i) {
		arr[i] = tempArr[i];
	}
	delete[] tempArr;

	std::cout << "reversed ";
	printArr(arr);

	return 0;
}
