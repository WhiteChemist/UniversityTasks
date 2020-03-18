#include "University_Task_4_2.h"
#include <iostream>

using namespace ut4_2;
using namespace std;

DoubleLinkedList* ut4_2::addNode(DoubleLinkedList* list,int value)
{
	DoubleLinkedList* temp = new DoubleLinkedList(value, NULL, NULL);
	list->next = temp;
	temp->next = NULL;
	temp->prev = list;
	list = temp;
	return list;
}

DoubleLinkedList* ut4_2::showListFromStart(DoubleLinkedList* list)
{
	auto temp = getPointerInTheStart(list);
	while (temp->next!=NULL)
	{
		cout << "Value: " << temp->value << " Next: " << temp->next << " Prev: " << temp->prev << endl;
		temp = temp->next;
	}
	return list;
}

DoubleLinkedList* ut4_2::showListFromEnd(DoubleLinkedList* list)
{
	auto temp = list;
	do
	{
		cout << "Value: " << temp->value << " Next: " << temp->next << " Prev: " << temp->prev << endl;
		temp = temp->prev;
	} while (temp->prev != NULL);
	return list;
}

DoubleLinkedList* ut4_2::addInStart(DoubleLinkedList* list,int value)
{
	auto ptr=getPointerInTheStart(list);
	DoubleLinkedList* temp = new DoubleLinkedList(value, NULL, NULL);
	ptr->prev = temp;
	temp->next = ptr;
	return list;
}

DoubleLinkedList* ut4_2::addInEnd(DoubleLinkedList* list,int value)
{
	auto ptr = list;
	DoubleLinkedList* temp = new DoubleLinkedList(value, NULL, NULL);
	while (true)
	{
		if (ptr->next == NULL)
		{
			ptr->next = temp;
			temp->prev = ptr;
			break;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return list;
}

DoubleLinkedList* ut4_2::deleteNegativeNodes(DoubleLinkedList* list)
{
	DoubleLinkedList* temp_node=new DoubleLinkedList();
	while (list->prev!=NULL)
	{
		if (list->value >= 0)
		{
			temp_node = list;
			list = list->prev;
		}
		else
		{
			auto temp = list;
			list = list->prev;
			temp_node->prev = list;
			list->next = temp_node;
			delete temp;
		}
	}
	return list;
}
DoubleLinkedList* ut4_2::getPointerInTheStart(DoubleLinkedList* list)
{
	auto ptr = list;
	auto result = new DoubleLinkedList();
	while (true)
	{
		if (ptr->prev == NULL)
		{
			result = ptr;
			return ptr;
		}
		else
		{
			ptr = ptr->prev;
		}
	}
}
void ut4_2::start()
{
	DoubleLinkedList* list = new DoubleLinkedList(55, NULL, NULL);
	for (int i = 0; i < 10; i++) { list=addNode(list, (-10 + rand() % 15)); }
	cout <<"Add 77 to start"<< endl;
	list=addInStart(list, 77);
	cout << "Add 99 to start" << endl;
	list=addInEnd(list, 99);
	cout << "All nodes: " << endl;
	list = showListFromEnd(list);
	cout << "Output from the start: " << endl;
	list=showListFromEnd(list);
	cout << endl;
	cout << "Output from the end: " << endl;
	list = showListFromStart(list);
	cout << endl;
	list=deleteNegativeNodes(list);
	cout << endl;
	list = showListFromStart(list);
	cout << endl;
}