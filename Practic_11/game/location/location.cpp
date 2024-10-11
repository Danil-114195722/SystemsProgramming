#include <iostream>
#include <unistd.h>

#include "../calls/calls.h"
#include "../calls/printing.h"

#include "../hospital/hospital.h"
#include "../shop/shop.h"
#include "../office/office.h"

#include "../main_vars/main_vars.h"
#include "../main_vars/printing.h"


using namespace std;


// печать приглашения игры и её краткого описания
void DisplayIntro() {
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	cout << "| Текстовая игра \"Ментолятор\" |" << endl;
	cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl << endl;
	cout << "Игра \"Ментолятор\" - это cимулятор мента.";
	cout << "\nНачав играть в Ментолятор, ты почуствуешь себя крутым ментом.";
	cout << "\nВ этой игре присутствуют мощные боёвки в сочетании с интереcной механикой здоровья, боекомплекта и выносливости!";
	cout << "\n\nТебя ждут вызовы, на которых придётся испытать удачу в победе над нарушителями закона.";
	cout << "\nВ игре предусмотрены различные локации вызовов с различным уровнем опасности.";
	cout << "\nЗа выполнение вызовов ты будешь получать кэш, необходимый для восстановления героя, и";
	cout << "\nочки заслуги, которые будут непосредственно влиять на твою пенсию.";
	cout << "\n\nОсновная задача игры - дослужить до пенсии и получить достаточное количество очков заслуги, чтобы";
	cout << "\nпрожить оставшиеся годы легко и с удовольствием.";
	cout << "\n\nИ помни, ты играешь за КРУТОГО мента, который в этом деле уже как 5 лет!";
	cout << "\nПоэтому вызовы будут непростые, а дожить до пенсии (которая начинается в " << pensionAge << " лет) будет ещё сложнее.";
	cout << endl << endl << endl;

	// подтверждение начала игры
	char* complete = new char;
	cout << "Итак, начать игру? [y, n] ";
	cin >> *complete;

	if (*complete != 'y') {
		gameOver = true;
	}
	delete complete;
}


// печать пенсии игрока в зависимости от его очков заслуги
void DisplayPensionEnd() {
	PrintState();
	cout << endl;

	cout << "Ты дослужился до пенсии!!!" << endl << endl;
	sleep(2);

	// среднее кол-во заслуги, которое возможно получить от 30 лет до пенсии
	int* avgScore = new int;
	*avgScore = int(((pensionAge - 30.0) / 5.0) * 300.0);

	int* percentScoreFloating = new int;
	*percentScoreFloating = int(float(*avgScore) * 0.15);

	if (score-300 < *avgScore-*percentScoreFloating) {
		cout << "Во время службы ты часто бездельничал, поэтому теперь ты";
		cout << "\nстал бомжом и побираешься на помойках :(" << endl;
	} else if (score-300 > *avgScore+*percentScoreFloating) {
		cout << "Почти всё время службы ты проводил на вызовах и пахал как конь,\nпоэтому теперь ты ";
		cout << "получаешь огромную пенсию и живёшь на Фиджи :D" << endl;
	} else {
		cout << "Ты хорошо служил, выполнял вызовы, когда это было необходимо, и";
		cout << "\nответственно подходил к своей работе, поэтому теперь ты";
		cout << "\nполучаешь неплохую пенсию и активно проводишь оставшиеся годы жизни :)" << endl;
	}

	delete avgScore;
	delete percentScoreFloating;
}


// печать текущей локации юзера и списка доступных действий
void CurrentLocation(Call* callList, int selectedCallIdx, Product* productList) {
	PrintState();

	// офис
	if (location == "office") {
		cout << "\nТекущее местоположение: офис" << endl;

		cout << "\nДоступные действия:" << endl;
		cout << "1. Посмотреть список вызовов [l]" << endl;
		cout << "2. Сходить на склад боеприпасов [s]" << endl;
		cout << "3. Поехать в больницу [h]" << endl;
		cout << "4. Поехать в магазин [m]" << endl;

	} else if (location == "officeStorage") {
		cout << "\nТекущее местоположение: офис - склад оружия и боеприпасов" << endl;

		cout << "\nДоступные действия:" << endl;
		cout << "1. Пополнить боекомплект [a]" << endl;
		cout << "2. Вернуться на рабочее место [q]" << endl;

	} else if (location == "officeCalls") {
		cout << "\nТекущее местоположение: офис - список активных вызовов" << endl;

		cout << "\nДоступные действия:" << endl;

		int* lastActionIdx = new int;
		*lastActionIdx = ActiveCallsCount(callList);

		for (int i = 0; i < *lastActionIdx; ++i) {
			cout << i+1 << ". ";
			PrintShortCall(callList[i]);
		}
		cout << *lastActionIdx+1 << ". Вернуться на рабочее место [q]" << endl;

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
	
	// магазин
	} else if (location == "shop") {
		cout << "\nТекущее местоположение: магазин" << endl;

		cout << "Доступные действия:" << endl;
		for (int i = 0; i < 3; ++i) {
			cout << i+1 << ". Купить товар \"" << productList[i].title << "\" (+" << productList[i].stamina;
			cout << " выносливости; -" << productList[i].cash << " кэша)" << endl;
		}
		cout << "4. Поехать в офис [o]" << endl;
	}
	cout << endl;
}


// переход в другую локацию или совершение действия
// возвращает номер выбранного вызова
int MakeAction(Call* callList, int selectedCallIdx, Product* productList) {
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
				// затраченное время на действие
				age += 0.1;
				break;
			// переход в больницу
			case 'h':
				cout << "Переход в: больница...\n" << endl;
				location = "hospital";
				// затраченное время на действие
				age += 0.2;
				break;
			// переход в магазин
			case 'm':
				cout << "Переход в: магазин...\n" << endl;
				location = "shop";
				// затраченное время на действие
				age += 0.3;
				break;
			// если было введено что-то другое
			default:
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
				break;
		}

	// офис - склад оружия и боеприпасов
	} else if (location == "officeStorage") {
		// будет хранить true, если боекомплект не полон и пополнится
		bool* wasFill = new bool;

		switch (action) {
			// пополнение боекомплекта и возвращение обратно, в офис
			case 'a':
				cout << "Пополнение боекомплекта...\n" << endl;
				*wasFill = FillAmmunition();
				cout << "Переход в: офис...\n" << endl;

				location = "office";
				// затраченное время на действие
				if (*wasFill) {
					age += 0.2;
				} else {
					age += 0.1;
				}

				delete wasFill;
				break;

			// переход назад, в офис
			case 'q':
				cout << "Переход в: офис...\n" << endl;
				location = "office";
				// затраченное время на действие
				age += 0.1;
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
			// будет содержать успех/неудачу выполнения вызова	
			bool ok;

			// принятие вызова
			case 'y':
				cout << "Принятие вызова..." << endl;
				sleep(1);
				cout << "Выезд на место преступления..." << endl;
				sleep(1);
				cout << "Прибытие на место преступления!" << endl;

				// выполнения вызова
				ok = PerformCall(callList[selectedCallIdx]);

				// если успех, то возвращение обратно, в офис
				if (ok) {
					// пересортировка массива с вызовами (удаление из массива выполненного вызова)
					RecollectCallList(callList, selectedCallIdx);
					// создание новых вызовов
					CreateCalls(callList);

					sleep(1);
					cout << "\nПереход в: офис...\n" << endl;
					location = "office";
				// если неудача, то заканчиваем игру
				} else {
					cout << "\nВы погибли при исполнении. Игра окончена. .  .    .       ." << endl << endl;
					gameOver = true;
				}
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
			// затраченное время на действие
			age += 0.2;
		} else {
			// преобразование строки в число
			int* chosenTreatment = new int;
			*chosenTreatment = action - '0';

			// если был введён номер лечения (какое кол-во сердечек восстановить)
			if (*chosenTreatment > 0 && *chosenTreatment <= maxHealth-health) {
				bool ok = Heal(*chosenTreatment);
				if (ok) {
					cout << "Лечение выполнено успешно! Восстановлено ";
					for (int i = 0; i < *chosenTreatment; ++i) {
						cout << "♥";
					}
					cout << endl << endl;
					// затраченное время на действие
					age += 0.1 * (*chosenTreatment);
				} else {
					cout << "Лечение не выполнено. Недостаточно кэша!\n" << endl;
					// затраченное время на действие
					age += 0.1;
				}

			// если было введено что-то другое
			} else {
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
			}

			// TODO: уменьшение выносливости на 5
			delete chosenTreatment;
		}

	// магазин
	} else if (location == "shop") {
		// переход в офис
		if (action == 'o') {
			cout << "Переход в: офис...\n" << endl;
			location = "office";
			// затраченное время на действие
			age += 0.3;
		} else {
			// преобразование строки в число
			int* chosenProduct = new int;
			*chosenProduct = action - '0';

			// если был введён номер товара
			if (*chosenProduct > 0 && *chosenProduct <= 3) {
				bool ok = BuyProduct(productList[*chosenProduct-1]);
				if (ok) {
					cout << "Продукт успешно употреблён!\n" << endl;
					UpdateRandomProducts(productList, *chosenProduct-1, 3);
				} else {
					cout << "Продукт не куплен. Недостаточно кэша!\n" << endl;
				}
				// затраченное время на действие
				age += 0.1;

			// если было введено что-то другое
			} else {
				cout << "Введено неверное действие! Изменений не произошло.\n" << endl;
			}

			delete chosenProduct;
		}
	}
	return 0;
}
