#include <iostream>
#include "University_Task_5.h"

//���������� ���������� �������� ���������� ���� �� 1 ������� �������
void zadanie5_1()
{
	std::cout << "������� 5 , ������� ������� ���������" << std::endl;

	int n, m;
	int count_of_zero = 0;
	std::cout << "������� ���������� �����: " << std::endl;
	std::cin >> n;
	std::cout << "������� ���������� ��������: " << std::endl;
	std::cin >> m;
	int** arr = new int* [n];//��������� ������ ��� ������
	for (int i = 0; i < m; i++)
		arr[i] = new int[m];//��������� ������ ��� �������

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
	std::cout << "���������� �������� ���������� ���� �� 1 ������� �������: " << count_of_zero << std::endl;

	for (int i = 0; i < m; i++)//���� ���� ��� ������������ ������ ���������� ��� �������
		delete[]arr[i];
	if (arr == NULL)
		std::cout << "������ �����������!" << std::endl;
}