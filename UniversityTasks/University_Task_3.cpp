#include <iostream>
#include "University_Task_3.h"

void zadanie3_1(const double PI)
{
	std::cout << "������� 3 , ������� ������� ���������" << std::endl;
	double Y, a, b, h, x;
	std::cout << "������� x:" << std::endl;
	std::cin >> x;
	a = -0.5;
	b = 2.5;
	h = 0.2;
	for (double i = a; i <= b; i += h)
	{
		Y = (double)(x * sin(PI / 4)) / (1 - 2 * x * cos(PI / 4) + pow(x, 2));
		std::cout << "i=" << i << std::ends << "x=" << x << std::ends << "Y=" << Y << std::endl;
	}
}