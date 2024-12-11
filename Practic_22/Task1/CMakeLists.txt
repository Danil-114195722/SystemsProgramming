# Проверка версии CMake (если версия меньше, то будет ошибка)
cmake_minimum_required(VERSION 3.2)

# Название проекта
project(project1)

# библиотека classes
add_library(classes
	./classes/Snack.cpp
	./classes/SnackSlot.cpp
	./classes/VendingMachine.cpp
)

# исполняемый файл с именем app
add_executable(app
	main.cpp
)

# Линковка программы с библиотеками
target_link_libraries(app classes)
