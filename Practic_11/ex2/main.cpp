#include <iostream>
#include "./services/calculate.h"


int main() {
	char action;
	int num1, num2;
	double quotient;

	while (true) {

		std::cout << "Введите действие (для выхода введите любой другой символ) [+ - * / ! ^]: ";
		std::cin >> action;
		

		switch (action) {
			case '+':
				std::cout << "Введите первое слагаемое: ";
				std::cin >> num1;
				std::cout << "Введите второе слагаемое: ";
				std::cin >> num2;

				std::cout << num1 << " + " << num2 << " = " << Add(num1, num2) << std::endl;
				break;
			case '-':
				std::cout << "Введите уменьшаемое: ";
				std::cin >> num1;
				std::cout << "Введите вычитаемое: ";
				std::cin >> num2;

				std::cout << num1 << " - " << num2 << " = " << Subtract(num1, num2) << std::endl;
				break;
			case '*':
				std::cout << "Введите первый множитель: ";
				std::cin >> num1;
				std::cout << "Введите второй множитель: ";
				std::cin >> num2;

				std::cout << num1 << " * " << num2 << " = " << Multiply(num1, num2) << std::endl;
				break;
			case '/':
				std::cout << "Введите делимое: ";
				std::cin >> num1;
				std::cout << "Введите делитель: ";
				std::cin >> num2;

				quotient = Divide(num1, num2);
				std::cout << num1 << " / " << num2 << " = " << quotient << std::endl;
				break;
			case '!':
				std::cout << "Введите число: ";
				std::cin >> num1;

				std::cout << num1 << "! = " << Factorial(num1) << std::endl;
				break;
			case '^':
				std::cout << "Введите число: ";
				std::cin >> num1;
				std::cout << "Введите степень: ";
				std::cin >> num2;

				std::cout << num1 << " ^ " << num2 << " = " << Power(num1, num2) << std::endl;
				break;
			default:
				std::cout << "Выход из программы..." << std::endl;
				return 0;
		}
	}
}

