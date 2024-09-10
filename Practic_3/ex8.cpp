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

	std::cout << "Enter the operator [+ - * / ! ^]: ";
	std::cin >> operat;
	
	double num1, num2, number, power;
	int num;

	switch (operat) {
		case '+':
			std::cout << "Enter the first number: ";
			std::cin >> num1;
			std::cout << "Enter the second number: ";
			std::cin >> num2;

			std::cout << num1 << " + " << num2 << " = " << num1+num2 << std::endl;
			break;
		case '-':
			std::cout << "Enter the first number: ";
			std::cin >> num1;
			std::cout << "Enter the second number: ";
			std::cin >> num2;

			std::cout << num1 << " - " << num2 << " = " << num1-num2 << std::endl;
			break;
		case '*':
			std::cout << "Enter the first number: ";
			std::cin >> num1;
			std::cout << "Enter the second number: ";
			std::cin >> num2;

			std::cout << num1 << " * " << num2 << " = " << num1*num2 << std::endl;
			break;
		case '/':
			std::cout << "Enter the first number: ";
			std::cin >> num1;
			std::cout << "Enter the second number: ";
			std::cin >> num2;

			std::cout << num1 << " / " << num2 << " = " << num1/num2 << std::endl;
			break;
		case '!':
			std::cout << "Enter the number: ";
			std::cin >> num;

			std::cout << num << "! = " << factorial(num) << std::endl;
			break;
		case '^':
			std::cout << "Enter the number: ";
			std::cin >> num;
			std::cout << "Enter the power: ";
			std::cin >> power;

			std::cout << num << " ^ " << power << " = " << pow(num, power) << std::endl;
			break;
		default:
			std::cout << "ERROR: invalid operator was given!" << std::endl; 
			break;
	}

	return 0;
}

