#include "funcs.h"


double multiplyOrAdd(double num1, double num2, bool add) {
	if (add) {
		return num1 + num2;
	} else {
		return num1 * num2;
	}
}


int countOdd(int* arr, int size) {
	int count = 0;

	for(unsigned i = 0; i < size; ++i) {
		if(arr[i] % 2 == 0) {
			count++;
		}
	}
	return count;
}


int sumArrNum(int num, int* arr) {
	return num + arr[num];
}
