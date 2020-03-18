#pragma once
namespace ut5_2
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
	}*first;

	Stack* Push(char value, Stack* stack);
	void Output(Stack* node);
	int getCountElements(Stack* node);
	void deleteNode(Stack** stack);
	bool isDigital(char symbol);
	double Rezult(std::string str,Stack* stack);
	Stack* outputStack(Stack* stack, char* value);
	int Prior(char a);
	void start();
}