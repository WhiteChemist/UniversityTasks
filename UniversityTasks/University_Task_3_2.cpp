#include "University_Task_3_2.h"
#include <iostream>


using namespace ut3_2;
using namespace std;



Stack* ut3_2::Push(int value, Stack* stack)
{
	Stack* localnode = new Stack(value);
	localnode->next = stack;
	return localnode;
}

void ut3_2::Output(Stack* node)
{
	int number = 1;
	do
	{
		cout << "Значение: " << node->value << " Адрес элемента: " << node << " Номер элемента: " << number << endl;
		node = node->next;
		number++;
	} while (node->next != NULL);
}

int ut3_2::getCountElements(Stack* node)
{
	int countelements = 1;
	while (node != NULL)
	{
		node = node->next;
		countelements++;
	}
	return countelements;
}

Stack* ut3_2::sortBySwapMemory(Stack* stack)
{
	Stack* temp = NULL;
	Stack* firstptr, * secondptr;
	if ((stack)->next->next != NULL)
		do
		{
			for (firstptr = stack; firstptr->next->next != temp; firstptr = firstptr->next)
			{
				if (firstptr->next->value > firstptr->next->next->value)
				{
					secondptr = firstptr->next->next;
					firstptr->next->next = secondptr->next;
					secondptr->next = firstptr->next;
					firstptr->next = secondptr;
				}
			}
		} while (stack->next->next != firstptr);
		return stack;
}

Stack* ut3_2::sortBySwapValue(Stack* stack)
{
	Stack* temp = stack;
	for (Stack* i = stack; i->next != NULL; i = i->next)
	{
		for (Stack* j = stack; j->next != NULL; j = j->next)
		{
			if (i->value < j->value)
			{
				int value = i->value;
				i->value = j->value;
				j->value = value;
			}
		}
	}
	return stack;
}

void ut3_2::deleteNode(Stack** stack)
{
	Stack* temp;
	if (stack == NULL)
	{
		cout << "Stack is empty" << endl;
	}
	else
	{
		temp = *stack;
		*stack = (**stack).next;
		delete temp;
	}
}

Stack* ut3_2::deleteNegativeNumbers(Stack* stack)
{
	Stack* temp_node = new Stack(0, NULL);
	int counter = 0;
	while (stack->next != NULL)
	{
		if (stack->value >= 0)
		{
			auto temp = stack;
			stack = stack->next;
			temp->next = temp_node;
			temp_node = temp;
		}
		else
		{
			auto temp = stack;
			stack = stack->next;
			delete temp;
		}

	}
	return temp_node;
}
void ut3_2::start()
{
	Stack* stack = new Stack(11, NULL);
	for (int i = 0; i < 10; i++) { stack = Push((-10 + rand() % 15), stack); }
	Output(stack);
	cout << "Delete negative elements..." << endl;
	stack = deleteNegativeNumbers(stack);
	cout << "Done!" << endl;
	Output(stack);
	cout <<"Sort ..."<< endl;
	stack = sortBySwapValue(stack);
	cout <<"Done!"<< endl;
	Output(stack);

}