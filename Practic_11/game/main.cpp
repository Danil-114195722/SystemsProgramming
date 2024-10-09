#include <iostream>
#include "./printing/printing.h"
#include "./services/services.h"
#include "./calls/calls.h"

using namespace std;


int main() {
	cout << "Игра \"Ментолятор\" (cимулятор мента)" << endl;

	PrintState();

	cout << "Rand: " << Randint(1, 5) << endl;

	Call newCall;
	GetRandomCall(&newCall);

	cout << endl;
	PrintShortCall(newCall);
	cout << endl;
	PrintFullCall(newCall);

	return 0;
}
