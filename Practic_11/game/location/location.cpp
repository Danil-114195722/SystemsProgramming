#include <iostream>
// #include <cstdlib>

#include "../calls/calls.h"
#include "../calls/printing.h"

#include "../main_vars/main_vars.h"
#include "../main_vars/printing.h"


using namespace std;


// печать приглашения игры и её краткого описания
void DisplayIntro() {
	cout << "Игра \"Ментолятор\" (cимулятор мента)" << endl;
	cout << endl;
}


// печать текущей локации юзера и списка доступных действий
void CurrentLocation(Call* callList, int selectedCallIdx) {
	PrintState();

	// офис
	if (location == "office") {
		cout << "\nТекущее местоположение: офис" << endl;

		cout << "\nДоступные действия:" << endl;
		cout << "1. Посмотреть список вызовов [l]" << endl;
		cout << "2. Сходить на склад боеприпасов [s]" << endl;
		cout << "3. Поехать в больницу [h]" << endl;

	} else if (location == "officeStorage") {
		cout << "\nТекущее местоположение: офис - склад оружия и боеприпасов" << endl;

		cout << "\nДоступные действия:" << endl;
		cout << "1. Пополнить боекомплект [a]" << endl;
		cout << "2. Вернуться на рабочее место [q]" << endl;

	} else if (location == "officeCalls") {
		cout << "\nТекущее местоположение: офис - список активных вызовов" << endl;

		cout << "\nДоступные действия:" << endl;

		int* lastActionIdx = new int;
		*lastActionIdx = 1;
		for (int i = 0; i < 9; ++i) {
			// проверка на наличие вызова на этом месте в массиве
			if (callList[i].isOccupied) {
				cout << i+1 << ". ";
				PrintShortCall(callList[i]);
				(*lastActionIdx)++;
			}
		}
		cout << *lastActionIdx << ". Вернуться на рабочее место [q]" << endl;

		delete lastActionIdx;

	} else if (location == "officeCallDesc") {
		cout << "\nТекущее местоположение: офис - описание вызова\n" << endl;

		PrintFullCall(callList[selectedCallIdx]);

		cout << "\nДоступные действия:" << endl;
		cout << "1. Принять вызов [y]" << endl;
		cout << "2. Назад к списку вызовов [q]" << endl;

	// больница
	} else if (location == "hospital") {
		cout << "\nТекущее местоположение: больница" << endl;

		cout << "\nДоступные действия:" << endl;

		int* lastActionIdx = new int;
		*lastActionIdx = 1;
		for (int i = 1; i <= maxHealth-health; ++i) {
			cout << i << ". Вылечиться на ";
			for (int j = 0; j < i; ++j) {
				cout << "♥";
			}
			cout << " (кэш: " << oneHeartPrice*i << ")" << endl;
			(*lastActionIdx)++;
		}

		cout << *lastActionIdx << ". Поехать в офис [o]" << endl;

		delete lastActionIdx;
	}
	cout << endl;
}


// переход в другую локацию или совершение действия
// возвращает номер выбранного вызова
int MakeAction(Call* callList) {
	// считывание действия от юзера
	char action;
	cout << "Введите действие: ";
	cin >> action;

	// офис
	if (location == "office") {
		switch (action) {
			case 'l':
			// переход в офис к списку активных вызовов
				cout << "Переход в: офис - список активных вызовов...\n" << endl;
				location = "officeCalls";
				break;
			// переход в офис на склад
			case 's':
				cout << "Переход в: офис - склад оружия и боеприпасов...\n" << endl;
				location = "officeStorage";
				break;
			// переход в больницу
			case 'h':
				cout << "Переход в: больница...\n" << endl;
				location = "hospital";
				break;
			// если было введено что-то другое
			default:
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
				break;
		}

	// офис - склад оружия и боеприпасов
	} else if (location == "officeStorage") {
		switch (action) {
			// пополнение боекомплекта и возвращение обратно, в офис
			case 'a':
				cout << "Пополнение боекомплекта...\n" << endl;

				// TODO: функция из пакета office для пополнения боекомплекта

				cout << "+ Боекомплект успешно пополнен!";
				cout << "Переход в: офис...\n" << endl;

				location = "office";
				break;

			// переход назад, в офис
			case 'q':
				cout << "Переход в: офис...\n" << endl;
				location = "office";
				break;

			// если было введено что-то другое
			default:
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
				break;
		}

	// офис - список активных вызовов
	} else if (location == "officeCalls") {
		// переход назад, в офис
		if (action == 'q') {
			cout << "Переход в: офис...\n" << endl;
			location = "office";
		} else {
			// преобразование строки в число
			int chosenCall = action - '0';

			// если был введён номер вызова
			if (chosenCall > 0 && chosenCall < 10) {
				// проверка вызова под этим номером (является ли он действительным в массиве вызовов)
				if (!(callList[chosenCall-1].isOccupied)) {
					cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
				// если вызова под этим номером нет (он не действительный)
				} else {
					cout << "Переход в: описание вызова " << chosenCall << "...\n" << endl;
					location = "officeCallDesc";
				}
			// если было введено что-то другое
			} else {
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
			}
			return chosenCall-1;
		}

	// офис - описание вызова
	} else if (location == "officeCallDesc") {
		switch (action) {
			// принятие вызова
			case 'y':
				cout << "Принятие вызова...\n" << endl;

				// TODO: поездка на место вызова
				// TODO: функция из пакета office для выполнения вызова
				cout << "БУДЕТ ВЫПОЛНЕНИЕ ВЫЗОВА" << endl;

				// если успех, то возвращение обратно, в офис
				// если неудача, то заканчиваем игру

				// TODO: поездка назад в офис
				cout << "Переход в: офис...\n" << endl;

				location = "office";
				break;

			// переход назад к списку вызовов
			case 'q':
				cout << "Назад к списку вызовов...\n" << endl;
				location = "officeCalls";
				break;

			// если было введено что-то другое
			default:
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
				break;
		}

	// больница
	} else if (location == "hospital") {
		// переход в офис
		if (action == 'o') {
			cout << "Переход в: офис...\n" << endl;
			location = "office";
		} else {
			// преобразование строки в число
			int* chosenTreatment = new int;
			*chosenTreatment = action - '0';

			// если был введён номер лечения (какое кол-во сердечек восстановить)
			if (*chosenTreatment > 0 && *chosenTreatment <= maxHealth-health) {
				
				// TODO: функция из пакета hospital для выполнения лечения
				cout << "Лечение ";
				for (int i = 0; i < *chosenTreatment; ++i) {
					cout << "♥";
				}
				cout << endl;

				cout << "Лечение успешно!" << endl;
			// если было введено что-то другое
			} else {
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
			}

			delete chosenTreatment;
		}
	}
	return 0;
}
