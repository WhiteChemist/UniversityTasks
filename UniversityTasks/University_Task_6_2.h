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
<<<<<<< HEAD
<<<<<<< HEAD
	BinaryTree* getPtrToNode(BinaryTree* node, int key);
	void searchInfoByKey(BinaryTree * tree,int key);
	void directByPass(BinaryTree* tree);
	void backwardByPass(BinaryTree* tree);
	void deleteNode(BinaryTree* tree,int key);
=======
	BinaryTree* freeMemory(BinaryTree* tree);
	BinaryTree* getPointerByKey(BinaryTree* tree,int value);
>>>>>>> abf6a25413ab6682933106ee327a195f4a22ccfc
=======
	BinaryTree* freeMemory(BinaryTree* tree);
	BinaryTree* getPointerByKey(BinaryTree* tree,int value);
>>>>>>> refs/remotes/origin/master
	void showTree(BinaryTree* tree);
	void start();
}

