// UniversityTasks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
#include "University_Task_2.h"
#include "University_Task_3.h"
#include "University_Task_4.h"
#include "University_Task_5.h"
#include "University_Task_6.h"
#include "University_Task_7.h"

const double PI = 3.1415926;

int main()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian_Russia.866");
	system("color 70");
	WorkWithStudent();
	system("pause");

	return 0;
}