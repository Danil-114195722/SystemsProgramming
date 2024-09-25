#include <iostream>


int copyCharArr(char* arrFrom, char* arrTo, int n = 0) {
	if (arrFrom[n] == '\0') {
		return 0;
	}
	arrTo[n] = arrFrom[n];
	return copyCharArr(arrFrom, arrTo, n+1);
}


int main() {
	char str[] = "Hello";
	int strSize = sizeof(str) / sizeof(str[0]);
	char strCopy[strSize] = {};

	std::cout << "str: " << str << std::endl;
	std::cout << "strCopy (empty)" << strCopy << std::endl;

	std::cout << "copying..." << std::endl;
	copyCharArr(str, strCopy);

	std::cout << "strCopy: " << strCopy << std::endl;

	return 0;
}
