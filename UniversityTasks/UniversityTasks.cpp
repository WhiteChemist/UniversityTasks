// UniversityTasks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
#pragma region Main_Headers
#include "University_Task_2.h"
#include "University_Task_3.h"
#include "University_Task_4.h"
#include "University_Task_5.h"
#include "University_Task_6.h"
#include "University_Task_7.h"
#include "University_Task_8.h"
#pragma endregion

using namespace std;
const double PI = 3.1415926;

int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 70");
	zadanie8_1(PI);
	system("pause");

	return 0;
}