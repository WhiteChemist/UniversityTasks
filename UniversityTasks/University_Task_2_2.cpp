#include "University_Task_2_2.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace ut2_2;
std::vector<Student>* students = new std::vector<Student>();
const double MINIMALPROFIT = 200.0 * 2;
void ut2_2::searchInFileLinear(std::string path)
{
	try
	{
		std::string FIO;
		std::cout << "Input FIO: ";
		std::cin >> FIO;
		bool isFound = false;
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (line.substr(_countof("FIO:") - 1, line.capacity()) == FIO) { isFound = true; }
				if (line.find("*") != std::string::npos && isFound == true) {
					break;
				}
				else if (line.find("FIO:") != std::string::npos && isFound == true)
				{
					std::cout << "FIO: " << line.substr(_countof("FIO:") - 1, line.capacity()) << std::endl;
				}
				else if (line.find("Group:") != std::string::npos && isFound == true)
				{
					std::cout << "Group: " << std::stoi(line.substr(_countof("Group:") - 1, line.capacity())) << std::endl;
				}
				else if (line.find("Average Mark:") != std::string::npos && isFound == true)
				{
					std::cout << "Average Mark: " << std::stod(line.substr(_countof("Average Mark:") - 1, line.capacity())) << std::endl;

				}
				else if (line.find("Profit:") != std::string::npos && isFound == true)
				{
					std::cout << "Profit: " << std::stod(line.substr(_countof("Profit:") - 1, line.capacity())) << std::endl;
				}
			}
			if (isFound != true)
			{
				std::cout << "Students hasn't been found" << std::endl;
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
void ut2_2::showStudent(Student student)
{
	std::cout << "Group:" << student.getGroup() << std::ends << "FIO:" << student.getFIO() << std::ends << "Average mark:" << student.getAverageMark() << std::ends << "Profit:" << student.getProfit() << std::endl;
}
void ut2_2::sortByAverageMark(std::vector<Student>* studentsa)
{
	for (int i = 0; i < (*studentsa).size(); i++)
	{
		for (int j = 0; j < (*studentsa).size(); j++)
		{
			if ((*studentsa)[i].getAverageMark() > (*studentsa)[j].getAverageMark())
			{
				auto temp = (*studentsa)[i];
				(*studentsa)[i] = (*studentsa)[j];
				(*studentsa)[j] = temp;
			}
		}
	}
	for (int j = 0; j < (*studentsa).size(); j++)
		showStudent((*studentsa)[j]);
}
std::vector<Student>* ut2_2::sortDirectSelection(std::vector<Student>* students)
{
	for (int i = 0; i < (*students).size() - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < (*students).size(); j++)
		{
			if ((*students)[j].getProfit() < (*students)[min].getProfit())
			{
				min = j;
			}
		}
		auto value = (*students)[i];
		(*students)[i] = (*students)[min];
		(*students)[min] = value;
	}
	return students;
}

void ut2_2::QuickSort(std::vector<Student>* students,int lleft,int rright)
{
	int left = lleft;
	int right = rright;
	double op_element = (*students)[abs((left - right)) / 2].getProfit();
	do
	{
		while ((*students)[left].getProfit() > op_element) { left++; }
		while ((*students)[right].getProfit() < op_element) { right--; }
		if (left <= right)
		{
			auto temp = (*students)[left];
			(*students)[left] = (*students)[right];
			(*students)[right] = temp;
			left++;
			right--;
		}
	} while (left < right);
	if (lleft < rright) QuickSort(students, lleft, right);
	if(left<rright)QuickSort(students, left, rright);
}
int ut2_2::searchBinary(std::vector<Student> students)
{
	double key;
	std::cout << "Input profit for a key: ";
	std::cin >> key;
	int midd = 0;
	int left = 0;
	int right = students.size();
	while (true)
	{
		midd = (left + right) / 2;

		if (key < students[midd].getProfit())
			right = midd - 1;
		else if (key > students[midd].getProfit())
			left = midd + 1;
		else
			return midd;
		if (left > right)
			return -1;
	}
}
Student* ut2_2::createStudent()
{
	int group;
	double profit;
	double average_mark;
	std::string FIO;
	std::cout << "Input group:" << std::ends;
	std::cin >> group;
	std::cout << "Input FIO:" << std::ends;
	std::cin >> FIO;
	std::cout << "Input profit:" << std::ends;
	std::cin >> profit;
	std::cout << "Input average mark:" << std::ends;
	std::cin >> average_mark;
	Student* student = new Student(FIO, group, average_mark, profit);
	return student;
}
void ut2_2::getListQeue(std::vector<Student> students)
{
	std::vector<Student>* vectorbygoodprofit = new std::vector<Student>();
	int index_good_profit = 0;
	for (int i = 0; i < students.size(); i++)
	{
		if (students[i].getProfit() < MINIMALPROFIT)
		{
			showStudent(students[i]);
			index_good_profit = i;
		}
		else if (students[i].getProfit() > MINIMALPROFIT)
		{
			(*vectorbygoodprofit).push_back(students[i]);
		}
	}
	sortByAverageMark(vectorbygoodprofit);

}

void ut2_2::showInterface()
{
	int value;
	std::string path;
	std::cout << "Input correct path: " << std::ends;
	std::cin >> path;
	FillArrayStudents(path);
	int counter;
	bool isExit = false;
	while (isExit == false)
	{
		std::cout << "0. Exit." << std::endl;
		std::cout << "1. Write in file." << std::endl;
		std::cout << "2. Show all students." << std::endl;
		std::cout << "3. Search in file linear." << std::endl;
		std::cout << "4. Quick sort." << std::endl;
		std::cout << "5. Sort array by direct selection." << std::endl;
		std::cout << "6. Binary search by profit." << std::endl;
		std::cout << "7. Create student and add to vector." << std::endl;
		std::cout << "8. Get Queue." << std::endl;
		std::cout << "Make a choice: " << std::endl;
		std::cin >> counter;
		switch (counter)
		{
		case 0:
			isExit == true;
			break;
		case 1:
			for (int i = 0; i < students->size(); i++)
				AddInFile((*students)[i], path);
			break;
		case 2:
			for (int i = 0; i < students->size(); i++)
				showStudent((*students)[i]);
			break;
		case 3:
			searchInFileLinear(path);
			break;
		case 4:
			QuickSort(students,0,students->size()-1);
			break;
		case 5:
			students = sortDirectSelection(students);
			break;
		case 6:
			value = searchBinary(*students);
			if (value != -1)
				showStudent((*students)[value]);
			break;
		case 7:
			students->push_back(*createStudent());
			break;
		case 8:
			getListQeue((*students));
			break;
		default:
			std::cout << "Incorrect value! If you want exit from program that input 0!" << std::endl;
			break;
		}
	}
}

void ut2_2::AddInFile(Student student, std::string path)//Функция для записи в файл
{
	try
	{
		std::ofstream file;
		file.open(path, std::ios::app);
		if (file.is_open())
		{
			file << "FIO:" << student.getFIO() << std::endl;
			file << "Group:" << student.getGroup() << std::endl;
			file << "Average Mark:" << student.getAverageMark() << std::endl;
			file << "Profit:" << student.getProfit() << std::endl;
			file << "*" << std::endl;
		}
		else
		{
			std::cout << "Error open file!" << std::endl;
		}
		file.close();
	}
	catch (const std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
void ut2_2::GetAllStudents(std::string path)	//Получение списка студентов из файла
{
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				std::cout << line << std::endl;
			}
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
void ut2_2::FillArrayStudents(std::string path)//Функция для парсинга из файла данных
{
	auto temp = new Student[GetCountStudents(path)];
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			for (int i = 0; i < GetCountStudents(path); i++)
			{
				while (std::getline(file, line))
					if (line.find("*") != std::string::npos)
					{
						students->push_back(temp[i]);
						i++;
					}
					else if (line.find("FIO:") != std::string::npos)
					{
						temp[i].setFIO(line.substr(_countof("FIO:") - 1, line.capacity()));
					}
					else if (line.find("Group:") != std::string::npos)
					{
						temp[i].setGroup(std::stoi(line.substr(_countof("Group:") - 1, line.capacity())));//делаем -1 т.к. не считывает первый символ фамилии

					}
					else if (line.find("Average Mark:") != std::string::npos)
					{
						temp[i].setAverageMark(std::stod(line.substr(_countof("Average Mark:") - 1, line.capacity())));

					}
					else if (line.find("Profit:") != std::string::npos)
					{
						temp[i].setProfit(std::stod(line.substr(_countof("Profit:") - 1, line.capacity())));

					}
			}
			std::cout << std::endl;
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
}
int ut2_2::GetCountStudents(std::string path)
{
	int count = 0;
	try
	{
		std::string line;
		std::ifstream file(path);
		if (file.is_open())
		{
			while (std::getline(file, line))
			{
				if (line.find("*") != std::string::npos)
				{
					count++;
				}
			}
		}
		file.close();
	}
	catch (std::exception & ex)
	{
		std::cout << ex.what() << std::endl;
	}
	return count;
}