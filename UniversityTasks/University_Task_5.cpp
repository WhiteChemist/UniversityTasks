#include <iostream>
#include "University_Task_5.h"

//подсчитать количество столбцов содержащих хотя бы 1 нулевой элемент
void zadanie5_1()
{
	std::cout << "Задание 5 , первого варинта сложности" << std::endl;

	int n, m;
	int count_of_zero = 0;
	std::cout << "Введите количество строк: " << std::endl;
	std::cin >> n;
	std::cout << "Введите количество столбцов: " << std::endl;
	std::cin >> m;
	int** arr = new int* [n];//выделение памяти под строки
	for (int i = 0; i < m; i++)
		arr[i] = new int[m];//выделение памяти под столбцы

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = (0 + rand() % 9);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			std::cout << std::ends << arr[i][j] << std::ends;
		}
		std::cout << std::endl;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				count_of_zero++;
				break;
			}
		}

	}
	std::cout << "Количество столбцов содержащих хотя бы 1 нулевой элемент: " << count_of_zero << std::endl;

	for (int i = 0; i < m; i++)//блок кода для освобождения памяти выделенной для массива
		delete[]arr[i];
	if (arr == NULL)
		std::cout << "Память освобождена!" << std::endl;
}