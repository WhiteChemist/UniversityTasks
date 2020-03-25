#include <iostream>
#include "University_Task_3_2.h"
#include <string>
#include "University_Task_5_2.h"
using namespace ut5_2_double;
using namespace std;
using namespace ut5_2_char;

void ut5_2_char::start()
{
	//double a = 3.1, b = 5.4, c = 0.2, d = 9.6, e = 7.8;
	string input = "a-(b+c*d)/e";
	auto temp = convertToOPZ(input);
	cout << "Poland record: " << temp<<endl;
	cout << "Result:" << getAnsword(temp) << endl;

}

Stack* ut5_2_char::Push(char value, Stack* stack)
{
	Stack* localnode = new Stack(value);
	localnode->next = stack;
	return localnode;
}

Stack* ut5_2_char::Pop(Stack* stack)
{
	Stack* temp;
	if (stack == NULL){
		cout << "Stack is empty" << endl;
	}
	else{
		temp = stack;
		stack = stack->next;
		delete temp;
	}
	return stack;
}

char ut5_2_char::Top(Stack* stack)
{
	return stack->value;
}

bool ut5_2_char::isEmpty(Stack* stack)
{
	int size = 0;
	auto ptr = stack;
	while (ptr != NULL)
	{
		size++;
		ptr = ptr->next;
	}
	return size == 0 ? true : false;
}

int ut5_2_char::getPriority(char symb)
{
	switch (symb) {
	case '*':
	case '/':
		return 3;
		break;

	case '+':
	case '-':
		return 2;
		break;

	case '(':
		return 1;
		break;

	case ')':
		return -1;
		break;
	default:
		return 0;
		break;
	}

}

std::string ut5_2_char::convertToOPZ(std::string str)
{
	string OPZ = "";
	Stack* stack = new Stack();
	int priority=0;
	for (int i = 0; i < str.length(); i++) {
		priority = getPriority(str[i]);

		if (priority == 0) {
			OPZ += str[i];
		}
		if (priority == 1) {
			stack = Push(str[i], stack);
		}
		if (priority > 1) {
			while (!isEmpty(stack)) {
				if (getPriority(Top(stack) >= priority)) {
					OPZ += Top(stack);
						stack=Pop(stack);
				}
				else break;
			}
			stack=Push(str[i],stack);
		}
		if (priority == -1) {
			while (getPriority(Top(stack) != 1)) {
				OPZ += Top(stack);
				stack = Pop(stack);
			}
			stack = Pop(stack);
		}
	}
	while (!isEmpty(stack)) {
		OPZ += Top(stack);
		stack = Pop(stack);
	}
	return OPZ;

}

double ut5_2_char::getAnsword(std::string OPZ)
{
	Stackd* stack=new Stackd();
	for (int i = 0; i < OPZ.length(); i++) {
		if ((int)OPZ[i] >= 97 && (int)OPZ[i] <= 122) {
			double temp;
			cout << "Input value: " << OPZ[i] << endl;
			cin >> temp;
			stack = Push(temp,stack);
		}
		else {
			double a = 0, b = 0;
			b = Top(stack);
			Pop(stack);
			a = Top(stack);
			Pop(stack);
			switch (OPZ[i]) {
			case'*':
				stack=Push(a * b,stack);
				break;
			case'/':
				stack = Push(a / b, stack);
				break;
			case'+':
				stack = Push(a + b, stack);
				break;
			case'-':
				stack = Push(a - b, stack);
				break;

			default:
				break;
			}
		}
	}
	return Top(stack);

}

Stackd* ut5_2_double::Push(double value, Stackd* stack)
{
	Stackd* localnode = new Stackd(value);
	localnode->next = stack;
	return localnode;
}

Stackd* ut5_2_double::Pop(Stackd* stack)
{
	Stackd* temp;
	if (stack == NULL) {
		cout << "Stack is empty" << endl;
	}
	else {
		temp = stack;
		stack = stack->next;
		delete temp;
	}
	return stack;
}

double ut5_2_double::Top(Stackd* stack)
{
	return	stack->value;
}
