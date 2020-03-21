#include "University_Task_6_2.h"
#include <iostream>
#include <ctime>


using namespace std;
using namespace ut6_2;


BinaryTree* ut6_2::addNode(BinaryTree* tree, int value)
{
	if (tree == NULL)
	{
		tree = new BinaryTree(value);
	}
	else
	{
		if (value == tree->value)
		{
			cout << "Error! Value must be unique!" << endl;
		}
		else if (value < tree->value)
		{
			tree->left = addNode(tree->left, value);
		}
		else if (value > tree->value)
		{
			tree->right = addNode(tree->right, value);
		}
	}
	return tree;
}

BinaryTree* ut6_2::balanceTree(BinaryTree* tree)
{
	return nullptr;
}

BinaryTree* ut6_2::initializeTree(int value)
{
	BinaryTree* tree = new BinaryTree();
	tree->value = value;
	tree->left = NULL;
	tree->right = NULL;
	return tree;
}

BinaryTree* ut6_2::freeMemory(BinaryTree* tree)
{
	return nullptr;
}

BinaryTree* ut6_2::getPointerByKey(BinaryTree* tree,int value)
{
	auto ptr = tree;
	bool isFound = false;
	while (tree!=NULL)
	{
		if (ptr->value == value)
		{
			isFound = true;
			break;
		}
		else if (ptr->value< value)
		{
			ptr = ptr->right;
		}
		else if (ptr->value > value)
		{
			ptr = ptr->left;
		}
	}
	if (isFound == false)
		cout << "Value not found!" << endl;
	return ptr;
}

void ut6_2::showTree(BinaryTree* tree)
{
	if (tree != NULL)
	{
		cout << tree->value << " ";
		showTree(tree->left);
		showTree(tree->right);
	}
}

void ut6_2::start()
{
	srand(time(0));
	auto tree = initializeTree(7);
	for (int i = 0; i < 20; i++)
		tree = addNode(tree, i);

	showTree(tree);
	cout << endl;
	auto ptr = getPointerByKey(tree, 9);
	
}
