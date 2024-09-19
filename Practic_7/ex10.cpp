#include <iostream>


int mergeAndCompare(int* arr1, int* arr2, int* size1, int* size2, int** mergedArr, int* mergedSize) {
	if (*size1 != *size2) {
		return -1;
	}

	*mergedSize = *size1 + *size2;
	*mergedArr = new int[*mergedSize];

	for (int i = 0; i < *size1; ++i) {
		(*mergedArr)[i] = arr1[i];
	}
	for (int i = *size1; i < *mergedSize; ++i) {
		(*mergedArr)[i] = arr2[i - *size1];
	}

	return 0;
}


void printArr(int* arr, int* size) {
	std::cout << " = [ ";
	for (int i = 0; i < *size; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}


int main() {
	int* size1 = new int;
	std::cout << "Enter size of first array: ";
	std::cin >> *size1;

	int* arr1 = new int[*size1];
	for (int i = 0; i < *size1; ++i) {
		std::cout << "Enter " << i+1 << " number: ";
		std::cin >> arr1[i];
	}

	int* size2 = new int;
	std::cout << "Enter size of second array: ";
	std::cin >> *size2;

	int* arr2 = new int[*size2];
	for (int i = 0; i < *size2; ++i) {
		std::cout << "Enter " << i+1 << " number: ";
		std::cin >> arr2[i];
	}

	std::cout << "arr1";
	printArr(arr1, size1);
	std::cout << "arr2";
	printArr(arr2, size2);

	int* mergedSize = new int;
	int* mergedArr = nullptr;

	int mergeRes = mergeAndCompare(arr1, arr2, size1, size2, &mergedArr, mergedSize);

	delete size1;
	delete[] arr1;
	delete size2;
	delete[] arr2;

	if (mergeRes == -1) {
		std::cout << "arr1 and arr2 have different sizes" << std::endl;
	} else {
		std::cout << "mergedArr";
		printArr(mergedArr, mergedSize);
	}

	delete mergedSize;
	delete[] mergedArr;

	return 0;
}
