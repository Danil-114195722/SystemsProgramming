#include <iostream>


bool isPalindrome(char* str, int size, int n = 0) {
	// size-1 потому что последний \0
	if (n == size-1) {
		return true;
	}

	if (str[n] == str[size-2-n]) {
		return true && isPalindrome(str, size, n+1);
	}
	return false;
}


int main() {
	char str[] = "abcba";
	int strSize = sizeof(str) / sizeof(str[0]);

	bool isP = isPalindrome(str, strSize);	
	if (isP) {
		std::cout << "String is palindrome: true" << std::endl;
	} else {
		std::cout << "String is palindrome: false" << std::endl;
	}

	return 0;
}
