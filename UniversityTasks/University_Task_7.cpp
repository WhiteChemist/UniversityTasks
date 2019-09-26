#include "University_Task_7.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <ostream>
#include <sstream>
#pragma warning(disable:4996)
using namespace std;
char* Surname = new char;
void WorkWithStudent()
{
	char path[256];
	int switcher = 0;
	bool exit = true;
	while (exit)
	{
		std::cout << "Make change:" << std::endl;
		std::cout << "0. Exit." << std::endl;
		std::cout << "1. Create new student and write him in file." << std::endl;
		std::cout << "2. Search good students from interesting you group." << std::endl;
		std::cout << "3. Print all students" << std::endl;
		std::cin >> switcher;
		switch (switcher)
		{
		case 0:
			exit = false;
			break;
		case 1:
			std::cout << "Input path file: " << std::endl;
			std::cin >> path;
			AddInFile(CreateStudent(), path);
			break;
		case 2:
			std::cout << "Input path file: " << std::endl;
			std::cin >> path;
			FillArrayStudents(path);
			break;
		case 3:
			std::cout << "Input path file: " << std::endl;
			std::cin >> path;
			GetAllStudents(path);
			break;
		default:
			std::cout << "Wrong number!" << std::endl;
			break;
		}
	}
}
Student CreateStudent()
{
	char Surname[256];
	int marks[3]{ 0,0,0 };
	int group = 0;
	std::cout << "Input Surname: " << std::endl;
	std::cin >> Surname;
	std::cout << "Input number group: " << std::endl;
	std::cin >> group;
	std::cout << "Input phys math: " << std::endl;
	std::cin >> marks[0];
	std::cout << "Input rate phys: " << std::endl;
	std::cin >> marks[1];
	std::cout << "Input rate computer science: " << std::endl;
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
			file << "*" << std::endl;
			file << "Group: " << student.GetGroup() << std::endl;
			file << "Surname: " << name << std::endl;
			file << "Average: " << student.GetAverageMark() << std::endl;
			file << "CompScience: " << student.GetCS() << std::endl;
			file << "Math: " << student.GetMath() << std::endl;
			file << "Phys: " << student.GetPhys() << std::endl;
			file << "*	" << std::endl;
		}
		else
		{
			std::cout << "Error open file!" << std::endl;
		}
		file.close();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what()<<std::endl;
	}
}
void GetAllStudents(char path[])	//Получение списка студентов из файла
{
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
			
				std::cout << line << std::endl;
			}
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
void SearchGoodStudents(int group, std::string path)// Поиск студентов со средним баллом выше 7
{
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				std::cout << line << std::endl;
			}
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
void FillArrayStudents(char path[])
{
	setlocale(LC_ALL, "Russian");

	char numb[] = { "Surname:" };
	std::string newf;
	int counter = 0;
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (line.find(numb) != std::string::npos)
				{
					counter++;
					newf = line.substr(_countof(numb), line.capacity());
					std::cout << newf;
				}
				else
				{
					cout << "Не найдено";
				}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	std::cout << counter << std::endl;
}