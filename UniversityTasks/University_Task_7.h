#ifndef UNIVERSITY_TASK_7
#define UNIVERSITY_TASK_7
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
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
	std::string Surname;
	int number_group;
	double average_mark;
	rating rate;
public:
	Student(std::string surname, int group, int phys, int math, int computer_science)
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
	void SetMath(int math)
	{
		this->rate.math = math;
	}
	int GetPhys()
	{
		return this->rate.phys;
	}
	void SetPhys(int phys)
	{
		this->rate.phys = phys;
	}
	int GetCS()
	{
		return this->rate.computer_science;
	}
	void SetCS(int computerscience)
	{
		this->rate.computer_science = computerscience;
	}
	std::string GetSurname()
	{
		return this->Surname;
	}
	void SetSurname(std::string surname)
	{
		this->Surname = surname;
	}
	double GetAverageMark()
	{
		return this->average_mark;
	}
	void SetAverageMark(double averagemark)
	{
		this->average_mark = averagemark;
	}
	void CalculateAverageMark()
	{
		this->average_mark = (double)(this->rate.computer_science + this->rate.math + this->rate.phys) / 3;
	}
	int GetGroup()
	{
		return this->number_group;
	}
	void SetGroup(int group)
	{
		this->number_group = group;
	}

};
void SearchGoodStudents(std::string path);
void WorkWithStudent();
Student CreateStudent();
void AddInFile(Student student, char path[]);
void GetAllStudents(char path[]);
void FillArrayStudents(char path[]);
int GetCountStudents(char path[]);

#endif