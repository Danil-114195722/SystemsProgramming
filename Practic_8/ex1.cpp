#include <iostream>


int arraySum(int* arr, int n) {
	if (n == 0) {
		return arr[0];
	}
	return arr[n] + arraySum(arr, n-1);
}


int main() {
	int arrSize;
	std::cout << "Enter arr size: ";
	std::cin >> arrSize;

	int* arr = new int[arrSize];
	for(int i = 0; i < arrSize; ++i) {
		std::cout << "Enter value i: ";
		std::cin >> arr[i];
	}

	int arrSum = arraySum(arr, arrSize-1);
	std::cout << "arrSum: " << arrSum << std::endl;

	delete[] arr;

	return 0;
}

