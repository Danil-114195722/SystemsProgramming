#include <iostream>
using namespace std;

#define PI 3.14159


int main() {
	double radius;

	cout << "Enter radius: ";
	cin >> radius;

	double len = 2 * radius * PI;
	cout << "Length: " << len << endl;

	return 0;
}
