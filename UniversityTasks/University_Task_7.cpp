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
		char* tempValue = student.Surname;
		//stud += "����� ������: " + student.number_group;
		//stud += "������: " + student.rate.phys;
		//stud += "����������: " + student.rate.math;
		//stud += "�����������: " + student.rate.computer_science;
		//stud += "������� ���: " + std::to_string(student.average_mark);
		std::ofstream file;
		file.open("text.txt");
		if (file.is_open())
		{
			std::cout << "���� ������!" << std::endl;
			file.write(student.Surname, strlen(student.Surname));
			file.write((char*)student.number_group, strlen((char*)student.number_group));
			file.write((char*)student.rate.computer_science, strlen((char*)student.rate.computer_science));
			file.write((char*)student.rate.math, strlen((char*)student.rate.math));
			file.write((char*)student.rate.phys, strlen((char*)student.rate.phys));
			//file.write(student.average_mark, strlen(student.average_mark));
		}
		file.close();
		
	}
	void View(int group, std::string path)
	{

	}
	