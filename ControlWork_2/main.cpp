#include <iostream>

#include "./ShoppingMall/ShoppingMall.h"
#include "./ShoppingMall/Floor.h"

#include "./Persons/IPerson.h"
#include "./Persons/Client.h"
#include "./Persons/Employee.h"
#include "./Persons/Inspector.h"

#include "./Shop/Product.h"
#include "./Shop/Shop.h"


void initShoppingMall(ShoppingMall* shoppingMall, Inspector** inspectorList) {
	// магазин 1
	Shop* shop1 = new Shop("Mustang Clothes", inspectorList[0]);
	// продукты магазина 1
	Product* product11 = new Product("Gray T-Short", "MUSTANG Bekleidungswerke GmbH & Co.KG,", "Germany");
	// работники магазина 1
	Employee* employee11 = new Employee("Maxim", "Pravy", 46, 26, 50000);
	Employee* employee12 = new Employee("Alexey", "Timchenko", 37, 15, 35000);
	// клиенты магазина 1
	Client* client11 = new Client("Nikita", "Nikitin", "+7(905)667-56-94");

	shop1->addProduct(product11);
	shop1->addEmployee(employee11);
	shop1->addEmployee(employee12);
	shop1->addClient(client11);

	// магазин 2
	Shop* shop2 = new Shop("H&M", inspectorList[0]);
	// продукты магазина 2
	Product* product21 = new Product("Gray T-Short", "Hennes & Mauritz", "Sweden");
	Product* product22 = new Product("Mustard Trousers", "Hennes & Mauritz", "Sweden");
	Product* product23 = new Product("Black cap", "Hennes & Mauritz", "Sweden");
	// работники магазина 2
	Employee* employee21 = new Employee("Elizaveta", "Popova", 29, 8, 40000);
	Employee* employee22 = new Employee("Darina", "Serova", 24, 5, 35000);
	Employee* employee23 = new Employee("Dmitry", "Sedov", 33, 15, 48000);
	// клиенты магазина 2
	Client* client21 = new Client("Andrey", "Sidorov", "+7(998)376-38-75");
	Client* client22 = new Client("Maxim", "Petrov", "+7(900)538-65-03");

	shop2->addProduct(product21);
	shop2->addProduct(product22);
	shop2->addProduct(product23);
	shop2->addEmployee(employee21);
	shop2->addEmployee(employee22);
	shop2->addEmployee(employee23);
	shop2->addClient(client21);
	shop2->addClient(client22);

	// магазин 3
	Shop* shop3 = new Shop("MVideo", inspectorList[1]);
	// продукты магазина 3
	Product* product31 = new Product("Laptop Huawei Matebook D16", "Huawei Technologies Co. Ltd.", "China");
	Product* product32 = new Product("Phone Samsung Galaxy A3", "Samsung Group", "Republic of Korea");
	Product* product33 = new Product("Beko Freeze", "Beko Electronic A. Ş.", "Turkey");
	Product* product34 = new Product("Xiaomi Robot Vacuum Cleaner", "Xiaomi", "China");
	// работники магазина 3
	Employee* employee31 = new Employee("Ann", "Vasilyeva", 50, 25, 45000);
	// клиенты магазина 3
	Client* client31 = new Client("Ivan", "Kruglov", "+7(909)256-35-80");

	shop3->addProduct(product31);
	shop3->addProduct(product32);
	shop3->addProduct(product33);
	shop3->addProduct(product34);
	shop3->addEmployee(employee31);
	shop3->addClient(client31);


	// этажи
	Floor* floor0 = new Floor(0);
	Floor* floor1 = new Floor(1);
	Floor* floor2 = new Floor(2);
	
	floor0->addShop(shop3);
	floor1->addShop(shop1);
	floor1->addShop(shop2);

	// добавление этажей в ТЦ
	shoppingMall->addFloor(floor0);
	shoppingMall->addFloor(floor1);
	shoppingMall->addFloor(floor2);
}

int main() {
	// проверяющие
	Inspector** inspectorList = new Inspector*[2]{
		new Inspector("Galina", "Ponchik", "+7(905)200-65-87", 30, 5),
		new Inspector("Fedor", "Gorny", "+7(903)683-62-65", 40, 20),
	};

	ShoppingMall* goldBabilon = new ShoppingMall("Gold Babilon");
	initShoppingMall(goldBabilon, inspectorList);
	goldBabilon->print();


	for(int i = 0; i < 2; ++i) {
		delete inspectorList[i];
	}
	delete[] inspectorList;
	delete goldBabilon;

	return 0;
}
