#include <iostream>

#include "./calls/calls.h"
#include "./calls/printing.h"

#include "./main_vars/main_vars.h"
#include "./main_vars/printing.h"


using namespace std;


int main() {
	cout << "Игра \"Ментолятор\" (cимулятор мента)" << endl;

	PrintState();

	Call newCall;
	GetRandomCall(&newCall);

	cout << endl;
	PrintShortCall(newCall);
	cout << endl;
	PrintFullCall(newCall);

	bool res = PerformCall(newCall);

	cout << "\nPerformed: " << boolalpha << res << endl;
	PrintState();

	return 0;
}
