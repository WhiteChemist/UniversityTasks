#pragma once
#include <iostream>
#include <string>
#include <vector>
namespace ut2_2 {
	struct Student
	{
	public:
#pragma region Getters
		std::string getFIO()
		{
			return this->FIO;
		}
		int getGroup()
		{
			return this->group;
		}
		double getAverageMark()
		{
			return this->average_mark;
		}
		double getProfit()
		{
			return this->profit;
		}
#pragma endregion
#pragma region Setters
		void setFIO(std::string FIO)
		{
			this->FIO = FIO;
		}
		void setGroup(int group)
		{
			this->group = group;
		}
		void setAverageMark(double average_mark)
		{
			this->average_mark = average_mark;
		}
		void setProfit(double profit)
		{
			this->profit = profit;
		}
#pragma endregion
		Student() {}
		Student(std::string FIO, int group, double average_mark, double profit)
		{
			this->FIO = FIO;
			this->group = group;
			this->average_mark = average_mark;
			this->profit = profit;
		}

	private:
		std::string FIO;
		int group;
		double average_mark;
		double profit;
	};
	void searchInFileLinear(std::string path);
	std::vector<Student>* sortDirectSelection(std::vector<Student>* students);
	void QuickSort(std::vector<Student>* students, int lleft, int rright);//Быстрая сортировка
	void AddInFile(Student student, std::string path);//Функция для записи в файл
	void GetAllStudents(std::string path);	//Получение списка студентов из файла
	void FillArrayStudents(std::string path);//Функция для парсинга из файла данных
	int GetCountStudents(std::string path);//Функция для получения количества студентов из файла
	void getListQeue(std::vector<Student> students);//Функция для получения очередности студентов по среднему доходу на каждого члена семьи
	void showInterface();//Функция для вывода интерфейса взаимодействия
	int searchBinary(std::vector<Student> students);//Функция бинарного поиска по ключу
	Student* createStudent();//Функция для создания студента
	void showStudent(Student student);//Функция вывода конкретного студента
void sortByAverageMark(std::vector<Student>* students);//Функция сортировки по среднему балу
}
