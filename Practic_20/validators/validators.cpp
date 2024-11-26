#include <iostream>
#include "validators.h"

using namespace std;


string validators::ValidateAlpha(string str) {
	for(int i = 0; i < str.length(); ++i) {
		if (!isalpha(str.at(i)) && !ispunct(str.at(i))) {
			cout << "Error: Invalid data was given!" << endl;
			return "-";
		}
	}
	return str;
}

int validators::ValidateNumber(int num) {
	if (num < 0) {
		cout << "Error: Invalid data was given!" << endl;
		return 0;
	}
	return num;
}
double validators::ValidateNumber(double num) {
	if (num < 0) {
		cout << "Error: Invalid data was given!" << endl;
		return 0;
	}
	return num;
}
