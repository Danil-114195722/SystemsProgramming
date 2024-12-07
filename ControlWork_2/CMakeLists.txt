# Проверка версии CMake (если версия меньше, то будет ошибка)
cmake_minimum_required(VERSION 3.2)

# Название проекта
project(shoppingMall)

# библиотека persons
add_library(persons
	./Persons/IPerson.cpp
	./Persons/Client.cpp
	./Persons/Employee.cpp
	./Persons/Inspector.cpp
)

# библиотека shop
add_library(shop
	./Shop/Product.cpp
	./Shop/Shop.cpp
)

# библиотека shoppingMall
add_library(shoppingMall
	./ShoppingMall/Floor.cpp
	./ShoppingMall/ShoppingMall.cpp
)

# исполняемый файл с именем app
add_executable(app
	main.cpp
)

# Линковка программы с библиотеками
target_link_libraries(app persons shop shoppingMall)
