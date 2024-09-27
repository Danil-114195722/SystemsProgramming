#include <iostream>
#include "module.h"

using std::cout;
using std::cin;
using std::endl;


// ОСНОВНАЯ ЗАДАЧА

void copyArray(int* arrFrom, int* arrTo, int size) {
	for(int i = 0; i < size; ++i) {
		arrTo[i] = arrFrom[i];
	}
}
void copyArray(double* arrFrom, double* arrTo, int size) {
	for(int i = 0; i < size; ++i) {
		arrTo[i] = arrFrom[i];
	}
}


// ДОП. ПРОЦЕДУРЫ


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
