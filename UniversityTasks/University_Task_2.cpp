#include <iostream>
#include "University_Task_2.h"

	void zadanie2_1(const double PI)
	{
		std::cout << "������� 2 , ������� ������� ���������" << std::endl;
		double y, x, b, z;
		std::cout << "������� �������� b:" << std::ends;
		std::cin >> b;
		std::cout << std::endl;
		std::cout << "������� �������� z:" << std::ends;
		std::cin >> z;
		std::cout << std::endl;
		if (z < 1)
		{
			std::cout << "�������� ����� � �������� z<1" << std::endl;
			x = (double)z / b;
		}
		else if (z >= 1)
		{
			std::cout << "�������� ����� � �������� z>=1" << std::endl;
			x = (double)sqrt(pow((z * b), 3));
		}
		y = (double)(-PI + pow(cos(pow(x, 3)), 2) + (pow(sin(pow(x, 2)), 3)));
		std::cout << "x=" << x << std::ends << "y=" << y << std::endl;
	}

