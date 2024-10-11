#include <iostream>
#include <unistd.h>
#include "./shop.h"

#include "../main_vars/main_vars.h"
#include "../services/services.h"

using namespace std;


// список продуктов
Product productList[10] = {
	Product{"Огурец", 2, 4},
	Product{"Багет французский", 4, 7},
	Product{"Жареные тараканы", 10, 5},
	Product{"Килька в томатном соусе", 9, 9},
	Product{"Доширак", 12, 10},
	Product{"Раки", 15, 10},
	Product{"Салат Цезарь", 18, 20},
	Product{"Пицца", 17, 15},
	Product{"Верблюжий горб", 20, 18},
	Product{"Шашлык", 25, 30},
};


// возвращает true, если product есть в массиве products
bool ProductInArray(Product* products, int size, Product product) {
    for (int i = 0; i < size; ++i) {
        if (products[i].title == product.title) {
            return true;
        }
    }
    return false;
}


// получение трёх (по умолчанию) случайных продуктов и запись их в массив shopProducts
void GetRandomProducts(Product* shopProducts, int count = 3) {
	// массив с индексами продуктов из общего списка, которые уже были добавлены в shopProducts
	int* excludedIdxs = new int[count];
	for (int i = 0; i < count; ++i) {
	 	excludedIdxs[i] = -1;
	}

	int* randIdx = new int;
	for (int i = 0; i < count; ++i) {
		while (true) {
			sleep(1);
			// получение случайного индекса продукта из общего списка
			*randIdx = Randint(0, 9);
			// если продукт для массива shopProducts новый, то прерываем while
			if (!(InArray(excludedIdxs, count, *randIdx))) {
				shopProducts[i] = productList[*randIdx];
				excludedIdxs[i] = *randIdx;
				break;
			}
		}
	}
	delete[] excludedIdxs;
	delete randIdx;
}


// обновление продукта (купленного) с индексом boughtProductIdx в массиве shopProducts (размером count, по умолчанию - 3)
void UpdateRandomProducts(Product* shopProducts, int boughtProductIdx, int count = 3) {
	int* newRandProductIdx = new int;
	while (true) {
		sleep(1);
		// получение случайного индекса продукта из общего списка
		*newRandProductIdx = Randint(0, 9);
		// если нового продукта нет в массиве shopProducts 
		if (!(ProductInArray(shopProducts, count, productList[*newRandProductIdx]))) {
			shopProducts[boughtProductIdx] = productList[*newRandProductIdx];
			delete newRandProductIdx;
			return;
		}
	}
	delete newRandProductIdx;
}


// возвращает true, если "покупка" продукта прошла успешно
bool BuyProduct(Product product) {
	// если не хватает кэша
	if (product.cash > cash) {
		return false;
	}
	// считывание кэша за покупку продукта
	cash -= product.cash;

	cout << "Употребление \"" << product.title << "\"..." << endl;
	cout << "-" << product.cash << " кэша" << endl;
	// добавление выносливости
	stamina += product.stamina;
	if (stamina > maxStamina) {
		cout << "+" << product.stamina - (stamina - maxStamina) << " выносливости" << endl;
		stamina = maxStamina;
	} else {
		cout << "+" << product.stamina << " выносливости" << endl;
	}
	return true;
}
