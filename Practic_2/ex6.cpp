#include <iostream>
using namespace std;

int main() {
	float cTemp;

	cout << "Enter Celsius: ";
	cin >> cTemp;

	float fTemp = (cTemp * 9) / 5 + 32;
	cout << "Enter Fahrenheit: " << fTemp << endl;

	return 0;
}
