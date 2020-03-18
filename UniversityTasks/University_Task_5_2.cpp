#include <iostream>
#include "University_Task_3_2.h"
#include <string>
#include <set>
#include <regex>
#include "University_Task_5_2.h"
using namespace std;
using namespace ut5_2;


double mas[255];
set <char> znak;
void ut5_2::start()
{
	//double a = 3.1, b = 5.4, c = 0.2, d = 9.6, e = 7.8;
	string input = "a-(b+c*d)/e",output="";
	first = NULL;
	char ss, aa;
	Stack* temp = first;
	int length = input.length(), k;
	for (k = 1; k <= length; k++)
	{
		ss = input[k];
		if (ss == '(')
		{
			first = Push(ss, first);
		}
		if (ss == ')')
		{
			while ((first->value)!='(')
			{
				first = outputStack(first, &ss);
				output += aa;
			}
			first = outputStack(first, &aa);
		}
		if (ss >= 'a' && ss <= 'z') output += ss;
		if (znak.find(ss) != znak.end())
		{
			while (first!=NULL&&Prior(first->value)>=Prior(ss))
			{
				first = outputStack(first, &aa);
				output += aa;
			}
			first = Push(ss, first);
		}
	}
	while (first!=NULL)
	{
		first = outputStack(first, &aa);
		output += &aa;
	}
	cout << output << endl;
}

Stack* ut5_2::Push(char value, Stack* stack)
{
	Stack* localnode = new Stack(value);
	localnode->next = stack;
	return localnode;
}

void ut5_2::Output(Stack* node)
{
	int number = 1;
	do
	{
		cout << "Значение: " << node->value << " Адрес элемента: " << node << " Номер элемента: " << number << endl;
		node = node->next;
		number++;
	} while (node->next != NULL);
}

int ut5_2::getCountElements(Stack* node)
{
	int countelements = 1;
	while (node != NULL)
	{
		node = node->next;
		countelements++;
	}
	return countelements;
}

void ut5_2::deleteNode(Stack** stack)
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

bool ut5_2::isDigital(char symbol)
{
	regex template_regex("^[a-z]{1}?");
	return regex_match(to_string(symbol), template_regex);
}

double ut5_2::Rezult(string str,Stack* stack)
{
	char ch, ch1, ch2;
	double op1, op2, rez;
	znak.insert('*');
	znak.insert('/');
	znak.insert('+');
	znak.insert('-');
	znak.insert('^');
	char chr = 'z' + 1;
	for (int i = 1; i <= str.length(); i++) {
		ch = str[i];
		if (znak.find(ch)==znak.end()) stack = Push(ch, stack);
		else {
			stack = outputStack(stack, &ch1);
			stack = outputStack(stack, &ch2);
			op1 = mas[int(ch1)];
			op2 = mas[int(ch2)];
				switch (ch) {
				case '+': rez = op2 + op1; break;
				case '-': rez = op2 - op1; break;
				case '*': rez = op2 * op1; break;
				case '/': rez = op2 / op1; break;
				case '^': rez = pow(op2, op1); break;
				}
			mas[int(chr)] = rez;
			stack = Push(chr, stack);
			chr++;
		}
	}
	return rez;
}

Stack* ut5_2::outputStack(Stack* stack, char* value)
{
	Stack* temp = stack;
	*value = stack->value;
	stack = stack->next;
	delete temp;
	return stack;
}
int ut5_2::Prior(char a) {
	switch (a) {
	case '^': return 4;
	case '*': case '/': return 3;
	case '-': case '+': return 2;
	case '(': return 1;
	}
	return 0;
}
