#include <iostream>
using namespace std;


int main() {
	int a = 10;
	int b = 20;
	int *ptrA;
	int *ptrB;

	ptrA = &a;
	ptrB = &b;

	cout << "Value of a: " << *ptrA << endl;
	cout << "Value of b: " << *ptrB << endl;

	*ptrB = *ptrA;
	cout << "After assigning b to a: " << *ptrB << endl;
	
	int *c = new int;
	*c = 30;
	cout << "Value of c: " << *c << endl;
	
	delete c;
	cout << "End of program." << endl;

	return 0;
}
