#include <iostream>
using namespace std;

int main() {
	int num;

	cout << "Enter number: ";
	cin >> num;

	if (num > 0 && num % 2 == 0) {
		cout << 1 << endl;
	} else {
		cout << 0 << endl;
	}

	return 0;
}
