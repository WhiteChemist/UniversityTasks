#include <iostream>
#include "University_Task_6.h"

//���� ������, ���������� ������ ����� ������ ����. ����������, ����������� �� ���, �.�. ��������� �� ����� ����� � ������ (12321). �������� 3
	//��������� ����� � ���������� ������.
void zadanie6_1(std::string str)
{
	int counterequals = 0;
	if (str.size() % 2 == 0)
	{
		int beforemiddle = str.size() / 2;//���������� ��������� ������ ��������
		int aftermiddle = str.size();
		for (int i = 0, j = aftermiddle - 1; i < beforemiddle; j > beforemiddle, i++, j--)
		{
			if ((int)str[i] == (int)str[j])
				counterequals++;
		}
		if (counterequals == (str.size() / 2))
		{
			std::cout << "��������� ������ �������� ������������" << std::endl;
		}
		else
		{
			std::cout << "��������� ������ ���������� ������������" << std::endl;

		}
	}
	else
	{
		int beforemiddle = str.size() / 2;
		int aftermiddle = str.size();
		for (int i = 0, j = aftermiddle - 1; i < beforemiddle; j > str.size() - beforemiddle, i++, j--)
		{
			if ((int)str[i] == (int)str[j])
				counterequals++;
		}
		if (counterequals == (str.size() / 2))
		{
			std::cout << "��������� ������ �������� ������������" << std::endl;
		}
		else
		{
			std::cout << "��������� ������ ���������� ������������" << std::endl;

		}
	}
}
