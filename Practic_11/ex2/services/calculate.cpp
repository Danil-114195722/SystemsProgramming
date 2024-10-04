#include <iostream>
#include "./calculate.h"


int Add(int a, int b) {
	return a + b;
}

int Subtract(int a, int b) {
	return a - b;

}

int Multiply(int a, int b) {
	return a * b;

}

double Divide(int a, int b) {
	if (b == 0) {
		std::cout << "ОШИБКА: делить на ноль нельзя!" << std::endl;
	}
	return double(a) / double(b);
}

int Factorial(int n) {
	if (n <= 1) {
		return 1;
	}

	return n * Factorial(n-1);
}

double Power(int base, int exponent) {
	if (exponent == 0) {
		return 1;
	}

	if (exponent > 0) {
		return double(base) * Power(base, exponent-1);
	} else {
		return 1/double(base) * Power(base, exponent+1);
	}
}
