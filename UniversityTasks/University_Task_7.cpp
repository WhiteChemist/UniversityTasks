#include "University_Task_7.h"
#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <ostream>
#include <vector>
#include <sstream>

//Необходимо создать структуру студента с полями фамилия, оценки по: математике, информатике, физике, и средний бал. 
//Необходимо сделать функцию для записи из структуры в файл и наоборот. Также необходимо написать фунцкию для поиска студента отличника


#pragma warning(disable:4996)
using namespace std;
const double GOODMARK = 7.0;//За отличника возьмем средний бал 7
vector<Student>* students;
Student* student = new Student;
void WorkWithStudent()
{

	char path[256];
	int switcher = 0;
	bool exit = true;
	std::cout << "Please input path for work:" << std::endl;
	std::cin >> path;
	students = new vector<Student>[GetCountStudents(path)];
	while (exit)
	{
		std::cout << "Make change:" << std::endl;
		std::cout << "0. Exit." << std::endl;
		std::cout << "1. Create new student and write him in file." << std::endl;
		std::cout << "2. Search good students from interesting you group." << std::endl;
		std::cout << "3. Print all students" << std::endl;
		std::cout << "4. Fill array students" << std::endl;
		std::cout << "5. Override path" << std::endl;
		std::cin >> switcher;
		switch (switcher)
		{
		case 0:
			exit = false;
			break;
		case 1:
			AddInFile(CreateStudent(), path);
			break;
		case 2:
			SearchGoodStudents(path);
			break;
		case 3:
			GetAllStudents(path);
			break;
		case 4:
			FillArrayStudents(path);
			break;
		case 5:
			std::cout << "Input new path" << std::endl;
			std::cin >> path;
			break;
		default:
			delete students;
			std::cout << "Wrong number!" << std::endl;
			break;
		}
	}
}
Student CreateStudent()//Функция для заполнения студента
{
	std::string Surname;
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
	Student student(Surname, group, marks[1], marks[0], marks[2]);
	return student;
}
void AddInFile(Student student, char path[])//Функция для записи в файл
{
	try
	{
		std::ofstream file;
		file.open(path, std::ios::app);
		if (file.is_open())
		{
			file << "Group:" << student.GetGroup() << std::endl;
			file << "Surname:" << student.GetSurname() << std::endl;
			file << "CompScience:" << student.GetCS() << std::endl;
			file << "Math:" << student.GetMath() << std::endl;
			file << "Phys:" << student.GetPhys() << std::endl;
			file << "Average:" << student.GetAverageMark() << std::endl;
			file << "*" << std::endl;
		}
		else
		{
			std::cout << "Error open file!" << std::endl;
		}
		file.close();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
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
void SearchGoodStudents(std::string path)// Поиск студентов со средним баллом выше 7
{
	try
	{
		for (int i = 0; i < (*students).size(); i++)
		{
			if ((*students)[i].GetAverageMark() > GOODMARK)
			{
				std::cout << "Good student: " << (*students)[i].GetSurname() << ". With average mark:" << (*students)[i].GetAverageMark() << std::endl;
			}
		}
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
void FillArrayStudents(char path[])//Функция для парсинга из файла данных
{
	auto temp = new Student[GetCountStudents(path)];
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			for (int i = 0; i < GetCountStudents(path); i++)
			{
				while (std::getline(file, line))
					if (line.find("*") != std::string::npos)
					{
						students->push_back(temp[i]);
						i++;

					}
					else if (line.find("Group:") != std::string::npos)
					{
						temp[i].SetGroup(std::stoi(line.substr(_countof("Group:") - 1, line.capacity())));//делаем -1 т.к. не считывает первый символ фамилии

					}
					else if (line.find("Surname:") != std::string::npos)
					{
						temp[i].SetSurname(line.substr(_countof("Surname:") - 1, line.capacity()));

					}
					else if (line.find("CompScience:") != std::string::npos)
					{
						temp[i].SetCS(std::stoi(line.substr(_countof("CompScience:") - 1, line.capacity())));

					}
					else if (line.find("Math:") != std::string::npos)
					{
						temp[i].SetMath(std::stoi(line.substr(_countof("Math:") - 1, line.capacity())));

					}
					else if (line.find("Phys:") != std::string::npos)
					{
						temp[i].SetPhys(std::stoi(line.substr(_countof("Phys:") - 1, line.capacity())));

					}
					else if (line.find("Average:") != std::string::npos)
					{
						temp[i].SetAverageMark(std::stod(line.substr(_countof("Average:") - 1, line.capacity())));

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
}
int GetCountStudents(char path[])
{
	int count = 0;
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (line.find("*") != std::string::npos)
				{
					count++;
				}
			}
		}
		file.close();
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return count;
}