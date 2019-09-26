#ifndef UNIVERSITY_TASK_7
#define UNIVERSITY_TASK_7
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
struct Student
{
private:
	struct rating
	{
		int phys;
		int math;
		int computer_science;
	};
	char* Surname;
	int number_group;
	double average_mark;
	rating rate;
public:
	Student(char* surname, int group, int phys, int math, int computer_science)
	{
		this->Surname = surname;
		this->number_group = group;
		rate.computer_science = computer_science;
		rate.math = math;
		rate.phys = phys;
		average_mark = (double)(phys + math + computer_science) / 3.0;
	}
	Student()
	{
		this->Surname = (char*)"default";
		this->number_group = 1;
		rate.computer_science = 1;
		rate.math = 1;
		rate.phys = 1;
		average_mark = (double)(rate.phys+rate.math+rate.computer_science) / 3.0;
	}
	int GetMath()
	{
		return this->rate.math;
	}
	int GetPhys()
	{
		return this->rate.phys;
	}
	int GetCS()
	{
		return this->rate.computer_science;
	}
	char* GetSurname()
	{
		return this->Surname;
	}
	double GetAverageMark()
	{
		return this->average_mark;
	}
	int GetGroup()
	{
		return this->number_group;
	}

};
void WorkWithStudent();
Student CreateStudent();
void AddInFile(Student student, char path[]);
void GetAllStudents(char path[]);
void FillArrayStudents(char path[]);
#endif