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
		std::cout << "�������� ����������� ��������:" << std::endl;
		std::cout << "0. �����." << std::endl;
		std::cout << "1. ������� �������� � �������� ��� � ����." << std::endl;
		std::cout << "2. ����� ���������� �� ������������ ������." << std::endl;
		std::cin >> switcher;
		switch (switcher)
		{
		case 0:
			exit = false;
			break;
		case 1:
			char path[256];
			std::cout << "������� ���� �� �����: " << std::endl;
			std::cin >> path;
			AddInFile(CreateStudent(), path);
			break;
		default:
			std::cout << "�������� �����!" << std::endl;
			break;
		}
	}
}
Student CreateStudent()
{
	char Surname[256];
	int marks[3]{ 0,0,0 };
	int group = 0;
	std::cout << "������� �������: " << std::endl;
	std::cin >> Surname;
	std::cout << "������� ����� ������: " << std::endl;
	std::cin >> group;
	std::cout << "������� ������ �� ����������: " << std::endl;
	std::cin >> marks[0];
	std::cout << "������� ������ �� ������: " << std::endl;
	std::cin >> marks[1];
	std::cout << "������� ������ �� �����������: " << std::endl;
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
			file << "�������: " << student.GetSurname() << std::endl;
			file << "����� ������: " << student.GetGroup() << std::endl;
			file << "������� ���� �� ���������: " << student.GetAverageMark() << std::endl;
			file << "������ �� �����������: " << student.GetCS() << std::endl;
			file << "������ �� ����������: " << student.GetMath() << std::endl;
			file << "������ �� ������: " << student.GetPhys() << std::endl;
			file << "**********" << std::endl;
		}
		else
		{
			std::cout << "������ �������� �����!" << std::endl;
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
