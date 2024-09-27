#include <iostream>
#include "123.h"

using std::cout;
using std::cin;
using std::endl;


void readArr(int* arr, int size) {
	for(int C = 0; C < size; C++) {
		cout << "Enter number [left " << size-C << "]: ";
		cin >> arr[C];
	}
}
void readArr(double* arr, int size) {
	for(int c = 0; c < size; c++) {
		cout << "Enter number [left " << size-c << "]: ";
	cin >> arr[c];
	}
}


void printArr(int* arr, int size) {
	cout << "arr = [ ";
	for(int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}
void printArr(double* arr, int size) {
	cout << "arr = [ ";
	for(int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}


int sumArr(int* arr, int size) {
	int sum = 0;

	for(int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
double sumArr(double* arr, int size) {
	double sum = 0;

	for(int i = 0; i < size; ++i) {
		sum += arr[i];
	}
	return sum;
}
