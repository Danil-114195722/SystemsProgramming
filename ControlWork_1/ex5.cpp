#include <iostream>
#include <cmath>


int factorial(int n) {
	if (n <= 1) {
		return 1;
	}

	return n * factorial(n-1);
}


int main() {
	char operat;

	std::cout << "Введите действие [+ - * / ! ^]: ";
	std::cin >> operat;
	
	double num1, num2, number, power;
	int num;

	switch (operat) {
		case '+':
			std::cout << "Введите первое слагаемое: ";
			std::cin >> num1;
			std::cout << "Введите второе слагаемое: ";
			std::cin >> num2;

			std::cout << num1 << " + " << num2 << " = " << num1+num2 << std::endl;
			break;
		case '-':
			std::cout << "Введите уменьшаемое: ";
			std::cin >> num1;
			std::cout << "Введите вычитаемое: ";
			std::cin >> num2;

			std::cout << num1 << " - " << num2 << " = " << num1-num2 << std::endl;
			break;
		case '*':
			std::cout << "Введите первый множитель: ";
			std::cin >> num1;
			std::cout << "Введите второй множитель: ";
			std::cin >> num2;

			std::cout << num1 << " * " << num2 << " = " << num1*num2 << std::endl;
			break;
		case '/':
			std::cout << "Введите делимое: ";
			std::cin >> num1;
			std::cout << "Введите делитель: ";
			std::cin >> num2;

			std::cout << num1 << " / " << num2 << " = " << num1/num2 << std::endl;
			break;
		case '!':
			std::cout << "Введите число: ";
			std::cin >> num;

			std::cout << num << "! = " << factorial(num) << std::endl;
			break;
		case '^':
			std::cout << "Введите число: ";
			std::cin >> num;
			std::cout << "Введите степень: ";
			std::cin >> power;

			std::cout << num << " ^ " << power << " = " << pow(num, power) << std::endl;
			break;
		default:
			std::cout << "ОШИБКА: Было передано неверное действие!" << std::endl; 
			break;
	}

	return 0;
}

