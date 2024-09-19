#define SIZE 5
#include <iostream>


int* findCommonElements(int* arr1, int* arr2) {
	int* resArray = new int[SIZE];
	int curIdx = 0;
	
	bool existFlag = false;

	for(unsigned i = 0; i < SIZE; ++i) {
		for(unsigned j = 0; j < SIZE; ++j) {
			// проверка на повтор числа
			for(unsigned k = 0; k < curIdx; ++k) {
				if (arr1[i] == resArray[k]) {
					existFlag = true;
					break;
				}
			}
			if(existFlag) {
				existFlag = false;
				break;
			}

			if(arr1[i] == arr2[j]) {
				resArray[curIdx] = arr1[i];
				curIdx++;
				break;
			}
		}
	}
	return resArray;
}


int main() {
	int array1[SIZE] = {5, 5, 9, 0, 2};
	int array2[SIZE] = {1, 2, 3, 4, 5};

	int* resArr = findCommonElements(array1, array2);

	std::cout << "array = [ ";
	for(unsigned i = 0; i < SIZE; ++i) {
		std::cout << resArr[i] << " ";
	}
	std::cout << "]" << std::endl;
	// OUTPUT: array = [ 5 2 0 0 0 ]

	delete[] resArr;

	return 0;
}

