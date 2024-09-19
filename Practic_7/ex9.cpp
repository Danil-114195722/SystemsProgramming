#define SIZE 5
#include <iostream>


void rotateArray(int* arr, int numRotate) {
	int* replaceIdx = new int;
	*replaceIdx = SIZE-1;
	int* newReplaceIdx = new int;

	int* tempValue = new int;
	*tempValue = arr[*replaceIdx];
	int* newTempValue = new int;

	int* iterCount = new int;
	*iterCount = 0;
	while (*iterCount <= SIZE) {
		*newReplaceIdx = *replaceIdx - (numRotate % SIZE);
		if(*newReplaceIdx < 0) {
			*newReplaceIdx += SIZE;
		}
		*newTempValue = arr[*newReplaceIdx];

		arr[*newReplaceIdx] = *tempValue;

		*tempValue = *newTempValue;
		*replaceIdx = *newReplaceIdx;

		*iterCount++;
	}
	delete replaceIdx;
	delete newReplaceIdx;
	delete tempValue;
	delete newTempValue;
}


int main() {
	int array[SIZE] = {1, 2, 3, 4, 5};
	int numRotate = 23;

	std::cout << "array before = [ ";
	for(unsigned i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "]" << std::endl;

	rotateArray(array, numRotate);

	std::cout << "array after = [ ";
	for(unsigned i = 0; i < SIZE; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "]" << std::endl;

	return 0;
}
