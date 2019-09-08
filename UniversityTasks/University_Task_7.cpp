#include <iostream>
#include "University_Task_7.h"

void zadanie7_1()
{
	struct Student
	{
		struct rating
		{
			int phys;
			int math;
			int computer_science;
			int chemistry;
		};
		std::string Surname;
		int year_of_birthday;
		int number_group;
		rating rate;

		void init(std::string surname, int group, int year, int phys, int math, int computer_science, int chemistry)
		{
			if (surname != "" && year != 0 && phys != 0 && math != 0 && computer_science != 0 && chemistry != 0 && group != 0)
			{
				this->Surname = surname;
				this->year_of_birthday = year;
				this->number_group = group;
				rate.chemistry = chemistry;
				rate.computer_science = computer_science;
				rate.math = math;
				rate.phys = phys;
			}
			else
			{
				std::cout << "Заполните все поля и попробуйте снова!";
			}
		}

	};
}