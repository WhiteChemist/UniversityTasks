#include "University_Task_7.h"
#include <iostream>
#include <stdio.h>
#include <ostream>
#include <sstream>
#pragma warning(disable:4996)
char* Surname = new char;
void WorkWithStudent()
{
	int switcher = 0;
	bool exit = true;
	while (exit)
	{
		std::cout << "Выберите необходимое действие:" << std::endl;
		std::cout << "0. Выход." << std::endl;
		std::cout << "1. Создать студента и записать его в файл." << std::endl;
		std::cout << "2. Найти отличников из интересующей группы." << std::endl;
		std::cin >> switcher;
		switch (switcher)
		{
		case 0:
			exit = false;
			break;
		case 1:
			char path[256];
			std::cout << "Введите путь до файла: " << std::endl;
			std::cin >> path;
			AddInFile(CreateStudent(), path);
			break;
		default:
			std::cout << "Неверный номер!" << std::endl;
			break;
		}
	}
}
Student CreateStudent()
{
	char Surname[256];
	int marks[3]{ 0,0,0 };
	int group = 0;
	std::cout << "Введите фамилию: " << std::endl;
	std::cin >> Surname;
	std::cout << "Введите номер группы: " << std::endl;
	std::cin >> group;
	std::cout << "Введите оценку по математике: " << std::endl;
	std::cin >> marks[0];
	std::cout << "Введите оценку по физике: " << std::endl;
	std::cin >> marks[1];
	std::cout << "Введите оценку по информатике: " << std::endl;
	std::cin >> marks[2];
	Student student(Surname,group,marks[1],marks[0],marks[2]);
	return student;
}
void AddInFile(Student student, char path[])
{
	try
	{
		std::ofstream file;
		file.open(path, std::ios::app);
		if (file.is_open())
		{
			file << "Фамилия: " << student.GetSurname() << std::endl;
			file << "Номер группы: " << student.GetGroup() << std::endl;
			file << "Средний балл по предметам: " << student.GetAverageMark() << std::endl;
			file << "Оценка по информатике: " << student.GetCS() << std::endl;
			file << "Оценка по математике: " << student.GetMath() << std::endl;
			file << "Оценка по физике: " << student.GetPhys() << std::endl;
			file << "**********" << std::endl;
		}
		else
		{
			std::cout << "Ошибка открытия файла!" << std::endl;
		}
		file.close();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what();
	}
}
void SearchGoodStudents(int group, std::string path)
{

}
