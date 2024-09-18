#include "funcs.h"


double multiplyOrAdd(double num1, double num2, bool add) {
	if (add) {
		return num1 + num2;
	} else {
		return num1 * num2;
	}
}
