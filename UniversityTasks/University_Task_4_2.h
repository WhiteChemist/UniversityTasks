#pragma once
#include <iostream>
namespace ut4_2
{
	struct DoubleLinkedList
	{
		int value;
		DoubleLinkedList* next;
		DoubleLinkedList* prev;
		DoubleLinkedList() {
			this->value = 0;
			this->next = NULL;
			this->prev = NULL;
		}
		DoubleLinkedList(int value, DoubleLinkedList* next, DoubleLinkedList* prev)
		{
			this->value = value;
			this->next = next;
			this->prev = prev;
		}
	};

	DoubleLinkedList* addNode(DoubleLinkedList* list, int value);
	DoubleLinkedList* showListFromStart(DoubleLinkedList* list);
	DoubleLinkedList* showListFromEnd(DoubleLinkedList* list);
	DoubleLinkedList* addInStart(DoubleLinkedList* list, int value);
	DoubleLinkedList* addInEnd(DoubleLinkedList* list,int value);
	DoubleLinkedList* deleteNegativeNodes(DoubleLinkedList* list);
	DoubleLinkedList* getPointerInTheStart(DoubleLinkedList* list);
	void start();
}
