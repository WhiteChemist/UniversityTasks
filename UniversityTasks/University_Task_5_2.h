#pragma once
#include <string>
namespace ut5_2_char
{
	struct Stack
	{
	public:
		char value;
		Stack* next;
		Stack()
		{
			this->value = 0;
		}
		Stack(int value)
		{
			this->value = value;
		}
		Stack(int value, Stack* next)
		{
			this->value = value;
			this->next = next;
		}
	};

	Stack* Push(char value, Stack* stack);
	Stack* Pop(Stack* stack);
	char Top(Stack* stack);
	bool isEmpty(Stack* stack);
	int getPriority(char symb);
	std::string convertToOPZ(std::string str);
	double getAnsword(std::string OPZ);
	void start();
}
namespace ut5_2_double
{
	struct Stackd
	{
	public:
		double value;
		Stackd* next;
		Stackd()
		{
			this->value = 0;
		}
		Stackd(int value)
		{
			this->value = value;
		}
		Stackd(int value, Stackd* next)
		{
			this->value = value;
			this->next = next;
		}
	};

	Stackd* Push(double value, Stackd* stack);
	Stackd* Pop(Stackd* stack);
	double Top(Stackd* stack);
}