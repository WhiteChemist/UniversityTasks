#ifndef UNIVERSITY_TASK_7
#define UNIVERSITY_TASK_7
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
struct Student
{
public:
	Student(std::string surname, int group, int year, int phys, int math, int computer_science)
	{
		this->Surname = surname;
		this->year_of_birthday = year;
		this->number_group = group;
		rate.computer_science = computer_science;
		rate.math = math;
		rate.phys = phys;
		average_mark = (double)(phys + math + computer_science) / 3.0;
	}
	struct rating
	{
		int phys;
		int math;
		int computer_science;
	};
	std::string Surname;
	int year_of_birthday;
	int number_group;
	double average_mark;
	rating rate;
};
void Creating(char path[], char mode[]);
void AddInFile(Student student, char path[]);
#endif