	#include "University_Task_7.h"
	#include <iostream>
	#include <stdio.h>
	#include <fstream>
	#include <sstream>
	#pragma warning(disable:4996)

	void Creating(char path[], char mode[])
	{
		try
		{
			FILE* file;
			file = fopen("text.txt", "w+t");
			fclose(file);
			delete file;
		}
		catch (int a)
		{
			std::cout << "Error number " + a;
		}
	}
	void AddInFile(Student student, char path[])
	{
		std::string stud = "Фамилия: " + student.Surname;
		stud += "Номер группы: " + student.number_group;
		stud += "Физика: " + student.rate.phys;
		stud += "Математика: " + student.rate.math;
		stud += "Информатика: " + student.rate.computer_science;
		stud += "Средний бал: " + std::to_string(student.average_mark);
		std::ofstream file;
		file.open("text.txt");
		if (file.is_open())
		{
			
			std::cout << "файл открыт!" << std::endl;
			file.write("qwe", strlen("qwe"));
		}
		file.close();
		
	}
	void View(int group, std::string path)
	{

	}
	