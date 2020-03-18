#pragma once
#include <iostream>
using namespace std;

namespace ut6_2
{
	struct BinaryTree
	{

		int value;
		BinaryTree* left;
		BinaryTree* right;
		BinaryTree()
		{
			this->value = 0;
			this->left = this->right = NULL;
		}
		BinaryTree(int value)
		{
			this->value = value;
			this->left = this->right = NULL;
		}
	};
	BinaryTree* addNode(BinaryTree* tree, int value);
	BinaryTree* balanceTree(BinaryTree* tree);
	BinaryTree* initializeTree(int value);
	void showTree(BinaryTree* tree);
	void start();
}

