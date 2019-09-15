// UniversityTasks.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "University_Task_2.h"
#include "University_Task_3.h"
#include "University_Task_4.h"
#include "University_Task_5.h"
#include "University_Task_6.h"
#include "University_Task_7.h"

const double PI = 3.1415926;

int main()
{
	system("color 70");
	setlocale(LC_ALL, "Russian");
	char Surname[] = "pavel";
	Student student(Surname,22,2000,6,7,8);
	char path[256];
	std::cout << "Введите путь до файла: "<<std::endl;
	std::cin >> path;
	char mode[3];
	std::cout << "Введите режим открытия файла: " << std::endl;
	std::cin >> mode;
	char filename[]{ "text.txt" };
	//Creating(path,mode);
	AddInFile(student, path);
	system("pause");
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
