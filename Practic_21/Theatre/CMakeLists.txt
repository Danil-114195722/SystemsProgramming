# Проверка версии CMake (если версия меньше, то будет ошибка)
cmake_minimum_required(VERSION 3.2)

# Название проекта
project(project1)

# библиотека persons
add_library(persons
	./Persons/IPerson.cpp
	./Persons/Client.cpp
	./Persons/IEmployee.cpp
	./Persons/Actor.cpp
	./Persons/Critic.cpp
)

# библиотека play
add_library(play
	./Play/Ticket.cpp
	./Play/Role.cpp
	./Play/Play.cpp
)

# библиотека theatre
add_library(theatre
	./Theatre/Hall.cpp
	./Theatre/Theatre.cpp
)

# исполняемый файл с именем app
add_executable(app
	main.cpp
)

# Линковка программы с библиотеками
target_link_libraries(app persons play theatre)
