// UniversityTasks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <Windows.h>
#pragma region Main_Headers
//#include "University_Task_2.h"
//#include "University_Task_3.h"
//#include "University_Task_4.h"
//#include "University_Task_5.h"
//#include "University_Task_6.h"
//#include "University_Task_7.h"
//#include "University_Task_8.h"
//#include "University_Task_1_2.h"
//#include "University_Task_2_2.h"
//#include "University_Task_3_2.h"
//#include "University_Task_4_2.h"
#include "University_Task_5_2.h"
//#include "University_Task_6_2.h"
//#include "University_Task_7_2.h"
#include <time.h>
#pragma endregion

using namespace std;
const double PI = 3.1415926;


int main()
{
	setlocale(LC_ALL, "Russian");
	system("color 70");
	srand(time(0));
	//ut1_2::test();
	//ut2_2::showInterface();
	//ut3_2::start();
	//ut4_2::start();
	ut5_2_char::start();
	//ut6_2::start();
	//ut7_2::start();
	system("pause");

	return 0;
}
