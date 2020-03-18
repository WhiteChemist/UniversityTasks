#pragma once
namespace ut3_2
{
	struct Stack
	{
	public:
		int value;
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

	Stack* Push(int value, Stack* stack);
	void Output(Stack* node);
	int getCountElements(Stack* node);
	Stack* sortBySwapMemory(Stack* stack);
	Stack* sortBySwapValue(Stack* stack);
	void deleteNode(Stack** stack);
	Stack* deleteNegativeNumbers(Stack* stack);
	void start();


}

//int main()
//{
//	setlocale(LC_ALL, "Russian");
//	Stack* stack = new Stack(11, NULL);
//	for (int i = 0; i < 10; i++) { stack = Push((-10 + rand() % 15), stack); }
//	/*Output(stack);
//	cout << endl;
//	stack=deleteNegativeNumbers(stack);
//	cout << endl;
//	Output(stack);*/
//	Stack* ste = new Stack;
//	for (int i = 0; i < 5; i++)
//	{
//		(*ste)[i] = new Stack;
//		cout << "value=" << ste[i].value << " stack" << &ste[i] << endl;
//	}
//}