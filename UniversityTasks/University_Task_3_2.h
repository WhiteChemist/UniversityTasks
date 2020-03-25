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
//	Stackd* stack = new Stackd(11, NULL);
//	for (int i = 0; i < 10; i++) { stack = Push((-10 + rand() % 15), stack); }
//	/*Output(stack);
//	cout << endl;
//	stack=deleteNegativeNumbers(stack);
//	cout << endl;
//	Output(stack);*/
//	Stackd* ste = new Stackd;
//	for (int i = 0; i < 5; i++)
//	{
//		(*ste)[i] = new Stackd;
//		cout << "value=" << ste[i].value << " stack" << &ste[i] << endl;
//	}
//}