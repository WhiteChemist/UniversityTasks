#include <iostream>
#include "University_Task_4.h"

void zadanie4_1()
{
	std::cout << "������� 4 , ������� ������� ���������" << std::endl;
	int index_last_positive_value = 0;
	int result = 0;
	int n;
	std::cout << "������� ���������� ��������� �������" << std::endl;
	std::cin >> n;
	int* arr = new int[n];
	if (arr != NULL && n <= 20 && n > 0)
	{
		int value_element;
		for (int i = 0; i < n; i++)
		{
			std::cout << "������� �������� �������� �������" << std::endl;
			std::cin >> value_element;
			arr[i] = value_element;
		}
		for (int i = 0; i < n; i++)
		{
			if (arr[i] > 0)
			{
				index_last_positive_value = i;
			}
			std::cout << arr[i] << std::ends;
		}
		std::cout << std::endl;
		for (int i = 0; i < index_last_positive_value; i++)
		{
			result += arr[i];
		}
		std::cout << "����� ��������� ������� �� ���������� �������������� ��������: " << result << std::endl;
		delete[]arr;
	}
	else
	{
		std::cout << "���������� ��������� ������ 20!" << std::endl;
	}

}